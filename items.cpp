class Items{
	
	private:
		float Price;
	
	protected:
		string Name;
	
	public:
		int check_number = 1;
		string description;
		//Setters
		void set_Name(string name){
			Name = name;
		}
		
		void set_Price(float price){
			Price = price;
		}	
		
		//Getters
		string get_Name(){
			return Name;
		}
		
		float get_Price(){
			return Price;
		}
		
		virtual void show(){
			cout<<Name<<endl;
			cout<<description<<endl;
			cout<<"Price: "<<Price<<endl<<endl;
		}
};

class Consumables : public Items{
	
	float Quantity = 0;
	
	public:
		//Setters
		void set_Quantity(float quantity){
			Quantity = quantity;
		}	
		
		//Getters
		float get_Quantity(){
			return Quantity;
		}
		
		void show() override{
			cout<<Name<<endl;
			cout<<description<<endl;
			cout<<"Quantity: "<<Quantity<<endl<<endl;
		}	
};
