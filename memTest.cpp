#include <iostream>
#include <memory>

class Entity{
	public:
		Entity()
		{
			std::cout << "Entity created" << std::endl;
		}
		~Entity()
		{
			std::cout << "Entity removed" << std::endl;
		}
};

int main()
{
	{
		std::shared_ptr<Entity> e0;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e0 = sharedEntity;
		}
	}


	std::cin.get();
}

