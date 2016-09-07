#include "ShapeManager.h"  

const int SM_CAPACITY = 50; 

ShapeManager::ShapeManager(int count){

                // Shapes, has to be a pointer, because without that, we would have a array of pointer of shapes
    // so then, when we create shapes = new Shape[30], it would create 30 shapes, initialize with null. With Shapes of pointer
    // we create shapes = Shapes*[30], so the we had  pointer of 30 position for an array of shape, so each pointer can point for a shape
    // and then, if we delete some position, we delete just the pointer for that array of shape, in the other type, we would delete
    // all array
	shapes = new Shape*[SM_CAPACITY];  // pointer to an array of shapes
	num_shapes = count; // how many shapes we actually have 

    for (int i = 0; i < SM_CAPACITY; i++)
    {
        shapes[i] = nullptr;
    }

	for (int i = 0; i < num_shapes; i++)
	{
		// for each pointer of the array, create a new shape
		shapes[i] = new Shape();
	}
}

ShapeManager::~ShapeManager(){

	for (int i = 0; i < num_shapes; i++)
	{
		// delete shape by shape inside of the array
		delete [] shapes[i];
	}

	// delete the array
	delete [] shapes;
	
}

void ShapeManager::randomize(const sf::Vector2u & window_size){

	for (int i = 0; i < num_shapes; i++)
    {
        // Generate random parameters
        int shape_width = rand() % 40 + 10;
        float x = rand() % (window_size.x - shape_width);
        float y = rand() % (window_size.y - shape_width);
        float vx = rand() % 400 - 200;
        float vy = rand() % 400 - 200;

        // Set randomly generated parameters.
        shapes[i]->setRadius(shape_width / 2);
        shapes[i]->setPosition(x, y);
        shapes[i]->setVelocity(vx, vy);
    }


}

void ShapeManager::moveAll(float time, const sf::Vector2u & window_size){

	 for (int i = 0; i < num_shapes; i++)
            shapes[i]->move(time, window_size);

     // check shape by shape, if they hit the wall, to then create a new one
     for (int i = 0; i < num_shapes; i++)
     {
        // get the new shape, if some shape had hit in the wall, or get null if didn't hit
     	Shape * sp = shapes[i]->getNewShape();

     	// if there's a new shape created by hiting the wall
     	if(sp != nullptr){

            if (num_shapes >= SM_CAPACITY)
            {
                delete sp;

            }
            else{
                // Generate random parameters
                int shape_width = rand() % 40 + 10;
                float x = rand() % (window_size.x - shape_width);
                float y = rand() % (window_size.y - shape_width);
                float vx = rand() % 400 - 200;
                float vy = rand() % 400 - 200;

                // Set randomly generated parameters.
                sp->setRadius(shape_width / 2);
                sp->setPosition(x, y);
                sp->setVelocity(vx, vy);

         		// put the new shape in the array of shapes 
                shapes[num_shapes] = sp;
                num_shapes++;
            }
     	}

        if(shapes[i] -> shouldBeDeleted()){

            delete shapes[i];

            // we can delete a shape in any position of the array
            // so then, we always get the last member of the array and put where we had delete the shape
            // then set null for the last position of the array
            shapes[i] = shapes[num_shapes -1]; 
            i--; //  repeat the loop for the position again, because new
            shapes[num_shapes -1] = nullptr;
            num_shapes--;

        }
     }


}

void ShapeManager::drawAll(sf::RenderWindow & window){

	for (int i = 0; i < num_shapes; i++)
	{
		shapes[i]->draw(window);
	}
}




