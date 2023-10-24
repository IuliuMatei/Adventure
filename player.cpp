class Player{
	private:
		string Name;
		float Money;
		int Hp = 100;
		int number_items = 0;
		
	public:
		int level;
		//Setters
		void set_Name(string name){
			Name = name;
		}
		
		void set_Money(float money){
			Money = money;
		}
		
		void set_Hp(int hp){
			Hp = hp;
		}	
		
		//Getters
		string get_Name(){
			return Name;
		}
		
		float get_Money(){
			return Money;
		}
		
		int get_Hp(){
			return Hp;
		}		
};

void create(Player *p){
	string name;
	float money;
	cout<<"Choose your name: ";
	cin>>name;
	p->set_Name(name);
	cout<<"Choose your amount of money: ";
	cin>>money;
	p->set_Money(money);
	p->level = 1;
}
