class Challenges{
	
	string Name;
	int Hp_r;
	int Level_r ;
	int Money;
	
	public:
		//Setters
		void set_Name(string name){
			Name = name;
		}
		
		void set_Hp(int hp_r){
			Hp_r = hp_r;
		}
		
		void set_Level(int level_r){
			Level_r = level_r;
		}
		
		void set_Money(int money){
			Money = money;
		}
		
		//Getters
		string get_Name(){
			return Name;
		}
		
		int get_Hp(){
			return Hp_r;
		}
		
		int get_Level(){
			return Level_r;
		}
		
		int get_Money(){
			return Money;
		}	
};

class Adventures{
	private:
		int Number_ch;
		
	public:
		Challenges *c;
	
	void set_Number(int number){
		Number_ch = number;
		c = new Challenges[10];
	}
	
	int get_Number(){
		return Number_ch;
	}
	
	void add_Ch(Challenges c1){
		c[Number_ch++] = c1;
	}
	
	void show(){
		for (int i = 0; i < Number_ch; i++){
			cout<<i+1<<". "<<c[i].get_Name()<<endl;
			cout<<"Hp required: "<<c[i].get_Hp()<<endl;
			cout<<"Level required: "<<c[i].get_Level()<<endl;
			cout<<"Reward: "<<c[i].get_Money()<<endl<<endl;
		}
	}
};

void create(Adventures *a){
	
	a->set_Number(0);
	
	Challenges c1, c2, c3;
	c1.set_Name("Help villagers");
	c1.set_Hp(0);
	c1.set_Level(1);
	c1.set_Money(5);
	a->add_Ch(c1);
	
	c2.set_Name("Fight demons");
	c2.set_Hp(50);
	c2.set_Level(5);
	c2.set_Money(50);
	a->add_Ch(c2);
	
	c3.set_Name("Save the princess");
	c3.set_Hp(99);
	c3.set_Level(20);
	c3.set_Money(1000);
	a->add_Ch(c3);
	
}
