#ifndef ECS_HPP
    #define ECS_HPP

        #include "../main.hpp"

        class Component;
        class Entity;
        class Manager;

        using component_type_id = std::size_t;

        inline component_type_id get_component_type_id() {
            static component_type_id last_id = 0;
            return last_id++;
        }

        template <typename T>
        inline component_type_id get_component_id() noexcept {
            static component_type_id type_id = get_component_type_id();
            return type_id;
        }

        constexpr std::size_t max_components = 32;

        using Component_bitset = std::bitset<max_components>;
        using Component_array = std::array<Component*, max_components>;

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
                bool active = true;
                std::vector<std::unique_ptr<Component>> components;
                Component_array component_array;
                Component_bitset component_bitset;

            public:
                void update();
                void draw();
                bool is_active();
                void destroy();

                template <typename T>
                bool has_components() const {
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
        };

        class Manager {
            private:
                std::vector<std::unique_ptr<Entity>> entities;

            public:
                void update();
                void draw();
                void refresh();

                Entity& add_entity();
        };

#endif