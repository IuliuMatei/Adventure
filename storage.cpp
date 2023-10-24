class Storage{
	protected:
		int Number_items = 0;
	
	public:
		//Setters
		void set_Number_items(int number_items){
			Number_items = number_items;
		}
		
		//Getters
		int get_Number_items(){
			return Number_items;
		}
		
		virtual void create_vector() = 0;
		virtual void show() = 0;
};

class Shop : public Storage{
	public:
		Items *item;
		
		void create_vector(){
			item = new Items[10];
		}
		
		void add_Item(Items item1){
			item[Number_items++] = item1;
		}
		
		void show(){
			for(int j=0;j < Number_items;j++){
		        cout<<j+1<<":";
		        item[j].show();
      		}
   		}
};

class Inventory: public Storage{
	public:
		Consumables *consumables;
		
		void create_vector(){
				consumables = new Consumables[10];
			}
			
		void add_Item(Consumables consumables1){
			consumables[Number_items++] = consumables1;
		}
			
		void show(){
				
			if(Number_items == 0)
				cout<<"The inventory is empty";
				
			for(int j=0;j < Number_items;j++){
			    cout<<j+1<<":";
			    consumables[j].show();
	      	}
	   	}
		
};

void create(Shop *shop){
	
	shop->create_vector();
	
	Items s1;
    s1.set_Name("Hp_potion");
    s1.set_Price(20);
    s1.description = "This item restors 10 hp of your maximum health";
    shop->add_Item(s1);
    
    Items s2;
    s2.set_Name("Water");
    s2.set_Price(10);
    s2.description = "Water keeps you hidrated throught your adventures";
    shop->add_Item(s2);
    
    Items s3;
    s3.set_Name("Sword");
    s3.set_Price(50);
    s3.description = "This item will help you fight the creatures you may encounter throught your adventures and also adds 1 to your level";
    shop->add_Item(s3);		
}

void show(Shop *shop){
	for(int i = 0; i < shop->get_Number_items(); i++){
		cout<<i+1<<":";
		shop->item[i].show();
	}
}
