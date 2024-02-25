#ifndef ECS_HPP
    #define ECS_HPP

        #include "../main.hpp"

        class Component;
        class Entity;
        class Manager;

        using Component_type_id = std::size_t;
        using Group = std::size_t;

        inline Component_type_id get_new_component_type_id() {
            static Component_type_id last_id = 0u;
            return last_id++;
        }

        template <typename T>
        inline Component_type_id get_component_id() noexcept {
            static Component_type_id type_id = get_new_component_type_id();
            return type_id;
        }

        constexpr std::size_t max_components = 32;
        constexpr std::size_t max_groups = 32;

        using Component_bitset = std::bitset<max_components>;
        using Component_array = std::array<Component*, max_components>;
        using Group_bitset = std::bitset<max_groups>;

        class Component {
            private:

            public:
                Entity* entity;

                virtual ~Component() {};

                virtual void init() {};
                virtual void update() {};
                virtual void draw() {};
        };

        class Entity {
            private:
                Manager& manager;
                bool active = true;
                std::vector<std::unique_ptr<Component>> components;
                Component_array component_array;
                Component_bitset component_bitset;
                Group_bitset group_bitset;

            public:
                Entity(Manager& m_manager) : manager(m_manager) {}

                void update();
                void draw();
                bool is_active();
                void destroy();

                template <typename T>
                bool has_component() const {
                    return component_bitset[get_component_id<T>()];
                }

                template <typename T, typename... T_args>
                T& add_component(T_args&&... m_args) {
                    T* c(new T(std::forward<T_args>(m_args)...));
                    c->entity = this;
                    std::unique_ptr<Component> u_ptr{c};
                    components.emplace_back(std::move(u_ptr));

                    component_array[get_component_id<T>()] = c;
                    component_bitset[get_component_id<T>()] = true;

                    c->init();
                    return *c;
                }

                template <typename T>
                T& get_component() const {
                    auto ptr = component_array[get_component_id<T>()];
                    return *static_cast<T*>(ptr);
                }

                bool has_group(Group m_group);
                void add_group(Group m_group);
                void del_group(Group m_group);

        };

        class Manager {
            private:
                std::vector<std::unique_ptr<Entity>> entities;
                std::array<std::vector<Entity*>, max_groups> grouped_entities;

            public:
                void update();
                void draw();
                void refresh();

                Entity& add_entity();
                void add_to_group(Entity* m_entity, Group m_group);
                std::vector<Entity*>& get_group(Group m_group);
        };

#endif