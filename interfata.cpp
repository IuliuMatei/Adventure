#include <iostream>
#include <string.h>
using namespace std;

#include "player.cpp";
#include "items.cpp";
#include "challenges.cpp";
#include "storage.cpp";
string name;
float money;

int main(){
	Player *player1 = new Player();
	Inventory *inventory = new Inventory();
	inventory->create_vector();
	Shop *shop = new Shop();
	create(shop);
	Adventures *adventure = new Adventures();
	create(adventure);
	
	mygame:
		cout<<"~~~~~~~~~~ MY GAME ~~~~~~~~~~"<<endl<<endl<<endl<<endl;
		cout<<"1. New game"<<endl;
		cout<<"2. Exit game";
		cout<<endl<<endl;
		cout<<"Your choice: ";
		int choice;
		cin>>choice;
		system("cls");
		
		switch(choice){
			
			case 1:
				create(player1);
				system("cls");
				goto home;
			
			case 2:
				return 1;
		}
		home:
			cout<<"~~~~~~~~~~ YOUR HOME ~~~~~~~~~~"<<endl<<endl<<endl<<endl;
			cout<<"Hp: "<<player1->get_Hp()<<endl;
			cout<<"Money: "<<player1->get_Money()<<endl;
			cout<<"Level: "<<player1->level<<endl<<endl;
			cout<<"1. See inventory"<<endl;
			cout<<"2. Go to shop"<<endl;
			cout<<"3. Earn money"<<endl<<endl;
			cout<<"Your choice: ";
			cin>>choice;
			system("cls");
		
		switch(choice){
			
			case 1:
				cout<<"~~~~~~~~~~ INVENTORY ~~~~~~~~~~"<<endl<<endl<<endl<<endl;
				inventory->show();
				cout<<endl<<endl;
				cout<<"1. Use hp potion"<<endl;
				cout<<"2. Go back home"<<endl<<endl;
				cout<<"Your choice: ";
				cin>>choice;
				system("cls");
				if (choice == 1){
					if (inventory->consumables[choice - 1].get_Quantity() >= 1){
						player1->set_Hp(player1->get_Hp() + 10);
						inventory->consumables[choice - 1].set_Quantity(inventory->consumables[choice - 1].get_Quantity() - 1);
						cout<<"Item used succesfully"<<endl<<endl;
						cout<<"Press 1 to go back: ";
						cin>>choice;
						system("cls");
						if (choice)
							goto home;
					}
					else{
						cout<<choice;
						cout<<"You do not have any hp potion"<<endl<<endl;
						cout<<"Press 1 to go back: ";
						cin>>choice;
						system("cls");
						if (choice)
							goto home;
						
					}
				}
				else if (choice == 2)
					goto home;
							
			shop:		
				case 2: 
					cout<<"~~~~~~~~~~ SHOP ~~~~~~~~~~"<<endl<<endl<<endl<<endl;
					show(shop);
					cout<<endl<<endl<<"Your money: "<<player1->get_Money()<<endl<<endl;
					cout<<"1. Buy Hp_potion"<<endl;
					cout<<"2. Buy Water"<<endl;
					cout<<"3. Buy Sword"<<endl;
					cout<<"4. Go home"<<endl<<endl;
					cout<<"Your choice: ";
					cin>>choice;
					system("cls");
					
					if (choice == 1 || choice == 2 || choice == 3){
						if (player1->get_Money() >= shop->item[choice - 1].get_Price()){
							if (shop->item[choice - 1].check_number == 0){
								for (int i = 0; i < inventory->get_Number_items(); i++){
									if (shop->item[choice - 1].get_Name() == inventory->consumables[i].get_Name()){
										inventory->consumables[i].set_Quantity(inventory->consumables[i].get_Quantity() + 1);
									}
										
								}
							}			
							else {
								Consumables *cons1 = new Consumables;
								cons1->set_Name(shop->item[choice - 1].get_Name());
								cons1->set_Price(shop->item[choice - 1].get_Price());
								cons1->description = shop->item[choice - 1].description;
								cons1->set_Quantity(1);
								inventory->add_Item(*cons1);
								shop->item[choice - 1].check_number = 0;
								delete cons1;
							}
							player1->set_Money(player1->get_Money() - shop->item[choice - 1].get_Price());
							if (shop->item[choice - 1].get_Name() == "Sword")
								player1->level = player1->level + 1;
							cout<<"Item bought succesfully"<<endl<<endl;
							cout<<"Press 1 to go back: ";
							cin>>choice;
							system("cls");
							if (choice)
								goto shop;
							
						}
						else{
							cout<<"You do not have money"<<endl;
							cout<<"Press 1 to go back home: ";
							cin>>choice;
							system("cls");
							if (choice)
								goto home;
						}
						
						
					}
					if (choice == 4)
						goto home;
			
				case 3:
					cout<<"~~~~~~~~~~ Challenges ~~~~~~~~~~"<<endl<<endl<<endl<<endl;
					adventure->show();
					cout<<endl<<endl;
					cout<<"Your choice: ";
					cin>>choice;
					system("cls");
					
					if (choice == 1){
						if (player1->get_Hp() > adventure->c[choice - 1].get_Hp() && player1->level >= adventure->c[choice - 1].get_Level()){
							cout<<"The villagers appreciate your help. You get 5 $"<<endl<<endl;
							player1->set_Money(player1->get_Money() + adventure->c[choice - 1].get_Money());
						}
						else if (player1->get_Hp() > adventure->c[choice - 1].get_Hp() && player1->level < adventure->c[choice - 1].get_Level())
							cout<<"You do not have the level required"<<endl<<endl;
						
						else if (player1->get_Hp() <= adventure->c[choice - 1].get_Hp()){
							cout<<"You died";
							goto dead;
						}
					}
					
					if (choice == 2){
						if (player1->get_Hp() > adventure->c[choice - 1].get_Hp() && player1->level >= adventure->c[choice - 1].get_Level()){
							cout<<"You fought the demons so heroic the villagers made a festival about you. You get 50 $"<<endl<<endl;
							player1->set_Money(player1->get_Money() + adventure->c[choice - 1].get_Money());
							player1->set_Hp(player1->get_Hp() - adventure->c[choice - 1].get_Hp());
						}
						else if (player1->get_Hp() > adventure->c[choice - 1].get_Hp() && player1->level < adventure->c[choice - 1].get_Level())
							cout<<"You do not have the level required"<<endl<<endl;
						
						else if (player1->get_Hp() <= adventure->c[choice - 1].get_Hp()){
							cout<<"You died";
							goto dead;
						}
					}
					
					if (choice == 3){
						if (player1->get_Hp() > adventure->c[choice - 1].get_Hp() && player1->level >= adventure->c[choice - 1].get_Level()){
							cout<<"The king was more than happy to see his daughter safe. You get 1000 $"<<endl<<endl;
							player1->set_Money(player1->get_Money() + adventure->c[choice - 1].get_Money());
							player1->set_Hp(player1->get_Hp() - adventure->c[choice - 1].get_Hp());
						}
						else if (player1->get_Hp() > adventure->c[choice - 1].get_Hp() && player1->level < adventure->c[choice - 1].get_Level())
							cout<<"You do not have the level required"<<endl<<endl;
						
						else if (player1->get_Hp() <= adventure->c[choice - 1].get_Hp()){
							cout<<"You died";
							goto dead;
						}
					}
					
					cout<<"Press 1 to go back home: ";
						cin>>choice;
						system("cls");
						if (choice)
							goto home;
					
				
		}
		dead:
			delete player1;
			delete shop;
			delete inventory;
			delete adventure;
}
