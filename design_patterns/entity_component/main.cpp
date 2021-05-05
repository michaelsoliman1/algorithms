#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "component.h"
#include "entity.h"

int main()
{
	auto* b = new Transform();
	auto* c = new Renderer();
    
   
	EntityManager* entityManager = new EntityManager();
    Entity* entity = entityManager->createEntity();

    entity->add(b);
    entity->add(c);
    
    //entity->print();
    
    
    auto* renderer = new Renderer();
    auto* transform = new Transform();
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
