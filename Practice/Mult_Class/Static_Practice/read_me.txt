Static is a old c/c++ practice, and it's stand for:

1)  Limit access to a fila
   if we put static in a function, it means that that function can be acess just inside of the file.
      ex: static void printArray();


2) Make variables persistant
   same of java in this case, the variable it's gonna be the same for all the variables, can use to count.
     ex:
     void getUniqueID(){

     	static int x=0;
     	x +=1;

     	cout << x << endl;
     }

     main(){

     	getUniqueID();
     	getUniqueID();
     	getUniqueID();
     }

     In this case, it'll print 1, 2 and 3, because we declare the static just once, then then secoond time and beyong we dont "declare" the variable any more, the it can be use as a count


3)  Create Class variables
4)  Cleate class functions
	Can be use to create a constant variable to a class
	ex:

	Class Robot
	{
		public:

			Robot(){

				cout<<"I am robot number: << ++pupulation"
			}

			static  int getPopulation(){
				return population;
			}

			static void setPopulation(int arg){
				populaton = arg;
			}

			~Robot(){ // decrease the population always when the robot is gonne
				pupulation--;
			}
		private:
			int energy;
			static int population;


	}

	int Robot::population = 0;

	In this case, population will be the same for all robots.
	Also, we have to initialize the variable, in this case, have to be outide of
	the Class and the main, like above.
	Also, we can have static functions, and in this case, like jave, we don't have 
	to create an object to use the function, like we can see in under, in the main

	int main(){

		cout<< Robot::getPopulation() << endl;
		// to use that, setPopulation has to be static
		Robot.setPopulation(4);
		Robot a;
		Robot b;



	}


