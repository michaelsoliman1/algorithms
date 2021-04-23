#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
 
class IComponent {
    public:
    virtual ~IComponent() {}
    virtual void print(){std::cout<<"this is base class"<<'\n';};
};
 
class Transform : public IComponent {
    public:
    Transform()=default;
    Transform(int _a){a= _a;};
    int a;
    
    void print(){std::cout<<"this is of type Transform "<< a <<'\n';};
};
class Renderer : public IComponent {
    public:
    void print(){std::cout<<"this is of type Renderer"<<'\n';};
};
 
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

	
int main()
{
	auto* b = new Transform(5);
	auto* c = new Renderer();
    
   
	EntityManager* entityManager = new EntityManager();
    Entity* entity = entityManager->createEntity();

    entity->add(b);
    entity->add(c);
    
    //entity->print();
    
    
    auto* renderer = new Renderer();
    auto* transform = new Transform(6);
    std::vector<IComponent*> reqComponents;
    reqComponents.push_back(renderer);
    reqComponents.push_back(transform);
    std::vector<Entity*> entitiesToRender = entityManager->getEntitiesHaving(reqComponents);
	for(auto& ent: entitiesToRender){
		renderer = dynamic_cast<Renderer*>(ent->get(renderer));
		transform = dynamic_cast<Transform*>(ent->get(transform));
	}
	
    renderer->print();
    transform->print();

 
}
