//
// Created by Michael Soliman on 05/05/2021.
//

#ifndef C_ENTITY_H
#define C_ENTITY_H

class Entity {
public:
    std::unordered_map<std::type_index, IComponent*> components;

    void print(){
        for(auto& [type, comp] : this->components){
            //std::cout<<type(typeid(comp))<<'\n';
            comp->print();
        }
    }

    template<typename T>
    void add(T a){
        components[std::type_index(typeid(*a))] = a;
        std::cout<<std::type_index(typeid(a)).name()<<'\n';
    }

    template<typename T>
    IComponent* get(T t){
        return components[std::type_index(typeid(*t))];
    }

};

class EntityManager {
public:
    std::vector<Entity*> entities = {};

    std::vector<Entity *> getEntitiesHaving(const std::vector<IComponent*>& reqComponents) {
        std::vector<Entity *> matchedEntities;
        for(auto& entity : entities){
            bool isMatched = true;
            for(auto& component : reqComponents){
                if(entity->get(component)== nullptr){
                    isMatched = false;
                    std::cout<<"false"<<'\n';
                }
            }
            if(isMatched){
                matchedEntities.push_back(entity);

            }

        }
        return matchedEntities;
    }
    Entity* createEntity() {
        Entity* entity = new Entity();
        this->entities.push_back(entity);
        return entity;
    }
};

#endif //C_ENTITY_H
