#ifndef ECS_HPP
    #define ECS_HPP

    #include "../main.hpp"

    class Component;
    class Entity;


    using component_type_id = std::size_t;

    inline component_type_id get_component_type_id();
    template <typename T> inline component_type_id get_component_id() noexcept;


    constexpr std::size_t max_components = 32;

    using component_bitset = std::bitset<max_components>;
    using component_array = std::array<Component*, max_components>;

    class Component {
        private:

        public:
            Entity* entity;

            Component();
            ~Component();
            
            virtual void init();
            virtual void update();
            virtual void draw();
    };

    class Entity {
        private:
            bool active = true;
            std::vector<std::unique_ptr<Component>> components;
            component_array component_array;
            component_bitset component_bitset;

        public:
            void update();
            void draw();
            bool is_active();
            void destroy();

            template <typename T> bool has_components() const;
    };

#endif