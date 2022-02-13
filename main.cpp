/************************************************CHRISTY'S SUPERMARKET APPLICATION*************************************************************************
****************************************************AUTHOR:JAMES CLETUS DCRUZ******************************************************************************
******************************************AdminstratorEmail id:jamescdcruz7@gmail.com *********************************************************************
*****************************************************Password:james@123************************************************************************************
Here I have created two access: one for the superuser or adminstrator and the other one for the buyer.Within the superuser ,he/she has the right to add new
proucts,modify excisting products where as the buyer has the right to view the special pricing as well as add different items to cart and reach checkout to
get the invoice at the end.********************************************************************************************************************************
***********************************************************************************************************************************************************
*/
#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;
int flag=0;
class user_access
{
private:
    string emailid="jamescdcruz7@gmail.com";
    string password="james@123";
private:
    string name;
    double price;
    string discount_name;
    double discount_value;
    int minimum_quantity_for_discount;
private:
    string item_name;
    int quantity;
    double cost_per_item;
    string discount_nam;
    double discount_price_per;
    int minimum_quantity_dis;

public:
    void get_credentials(string x,string y)
    {
        emailid=x;
        password=y;
    }
public:
    void user();
    void Superuser();
    void Superuser_rights();
    void add_newProduct();
    void modify_product();
    void display_products();
    void Buyer();
    void specialPricing();
    void addtocart();
    void invoice_generation();
};
void user_access::user()
{
    string option;
    cout<<setw(200)<<"##############################################################################################################################################################################################"<<endl;
    cout<<setw(200)<<"**********************************************************************************************************************************************************************************************"<<endl;
    cout<<setw(100)<<"\t SUPER MARKET APPLICATION \t"<<endl;
    cout<<setw(200)<<"##############################################################################################################################################################################################"<<endl;
    cout<<setw(200)<<"**********************************************************************************************************************************************************************************************"<<endl;
    cout<<left<<setw(100)<<"\t Please choose the level of access for the Supermarket Application \t"<<endl;
    cout<<setw(100)<<"\t Type <1> for Superuser \t"<<endl;;
    cout<<setw(100)<<"\t Type <2> for Buyer \t"<<endl;

    cin>>option;
    if(option=="1")
    {
        user_access::Superuser();
    }
    else if(option=="2")
    {
        user_access::Buyer();
    }
    else
    {
        cout<<left<<setw(100)<<"Wrong input entered"<<endl;
        cout<<left<<setw(100)<<"Try again"<<endl;
        user_access::user();
    }

}

void user_access::Superuser()
{
    string a;
    string b;
    cout<<left<<setw(100)<<"Enter adminstrator Email id "<<endl;
    cin>>a;
    cout<<left<<setw(100)<<"Enter your Password"<<endl;
    cin>>b;

    if(emailid.compare(a) == 0 && password.compare(b)==0 )
    {
        cout<<left<<setw(100)<<"Admininstrator Access Granted"<<endl;
        user_access::Superuser_rights();

    }
    else
    {
        cout<<left<<setw(100)<<"Administrator Acess Denied "<<endl;
        cout<<left<<setw(100)<<"Try Again"<<endl;
        user_access::Superuser();
    }
}

void user_access::Buyer()
{
    string choice;
    cout<<left<<setw(100)<<"Type <1> see the special pricing"<<endl;
    cout<<left<<setw(100)<<"Type <2> to scan and add items to cart"<<endl;
    cout<<left<<setw(100)<<"Type <3> to exit and go back to main menu"<<endl;
    cin>>choice;
    if(choice=="1")
    {
        user_access::specialPricing();
    }
    else if(choice=="2")
    {
        flag=0;
        user_access::addtocart();
    }
    else if(choice=="3")
    {

        cout<<left<<setw(100)<<"Going back to main menu"<<endl;
        user_access::user();
    }
    else
    {
        cout<<left<<setw(100)<<"Invalid entry"<<endl;
        cout<<left<<setw(100)<<"Try Again"<<endl;
        user_access::Buyer();
    }
}
void user_access::specialPricing()
{
    fstream store_database;
    store_database.open("supermarket_database.txt",ios::in);
    if(store_database.is_open())
    {
        while(store_database >> name >> price>> discount_name >> discount_value>> minimum_quantity_for_discount)
        {
            cout<<"\t Product name: "<<left<<setw(10)<<name<<"\t Cost of one item: $"<<setw(10)<<setprecision(2)<<price<<"\t Discount Available: "<<setw(20)<<discount_name<<"\t %age Discount: "<<setw(10)<<setprecision(2)<<100*discount_value<<"\t Minimum quantity to get discount: "<<setw(10)<<minimum_quantity_for_discount<<endl;
        }
        store_database.close();
    }

    user_access::Buyer();
}
void user_access::addtocart()
{
    fstream invoice;
    if(flag==0)
    {
        invoice.open("buyer_invoice.txt",ios::out);
    }
    else
    {
        invoice.open("buyer_invoice.txt",ios::app);
    }
    if(invoice.is_open())
    {

        cout<<left<<setw(100)<<"Enter the item you wish to add to cart"<<endl;
        cin>>item_name;
        string quantity_string;
        int count=0;

        fstream store_database;
        store_database.open("supermarket_database.txt",ios::in);;
        if(store_database.is_open())
        {
            while(store_database >> name >> price>> discount_name >> discount_value>> minimum_quantity_for_discount)
            {
                if(item_name==name)
                {
                    cout<<left<<"Enter the quatitity of "<<item_name<<" you like to buy"<<endl;
                    cin>>quantity_string;
                    quantity=stoi(quantity_string);
                    cost_per_item=price;
                    discount_nam=discount_name;
                    discount_price_per=discount_value;
                    minimum_quantity_dis=minimum_quantity_for_discount;
                    invoice<<"\t"<<item_name<<"\t"<<quantity<<"\t"<<cost_per_item<<"\t"<<discount_nam<<"\t"<<discount_price_per<<"\t"<<minimum_quantity_dis<<endl;
                    flag+=1;
                    count=1;
                }

            }
            store_database.close();
            if(count==0)
            {
                cout<<left<<setw(100)<<"Item is not found in the database"<<endl;
                cout<<left<<setw(100)<<"Try again"<<endl;
                user_access::addtocart();
            }
        }
        invoice.close();
    }
    cout<<left<<setw(100)<<"Do you want to add more products to cart"<<endl;
    string s;
    cout<<left<<setw(100)<<"Type <1> to add more product" <<endl;
    cout<<left<<setw(100)<<"Type <2> to procede to checkout and generate invoice" <<endl;
    cin>>s;
    if(s=="1")
    {
        user_access::addtocart();
    }
    else if(s=="2")
    {
        user_access::invoice_generation();
    }
    else
    {
        cout<<left<<setw(100)<<"Invalid input and Try again "<<endl;
        user_access::addtocart();
    }

}

void user_access::invoice_generation()
{
    double total_price_1=0;
    double total_price_2=0;
    double grand_total=0;
    double your_savings=0;
    fstream invoice;
    invoice.open("buyer_invoice.txt",ios::in);
    if(invoice.is_open())
    {
        cout<<left<<setw(100)<<"\t INVOICE"<<endl;
        while(invoice>>item_name>>quantity>>cost_per_item>>discount_nam>>discount_price_per>>minimum_quantity_dis)
        {
            cout<<"\t Item Name: "<<left<<setw(10)<<item_name<<"\t Quantity :"<<setw(10)<<quantity<<"\t  Cost Per Item: $"<<setw(5)<<setprecision(2)<<cost_per_item<<"\t Discount Available :"<<setw(20)<<discount_nam<<"\t Percetage Discount:"<<setw(10)<<setprecision(2)<<100*discount_price_per<<"\t Minimum Quantity to avail Discount:"<<setw(10)<<minimum_quantity_dis<<endl;
            if(quantity>minimum_quantity_dis || quantity==minimum_quantity_dis)
            {
                total_price_1=total_price_1+quantity*cost_per_item*(1-discount_price_per);
                your_savings=your_savings+quantity*cost_per_item*discount_price_per;
            }
            else
            {
                total_price_2=total_price_2+quantity*cost_per_item;
            }
        }
        grand_total=total_price_1+total_price_2;

        int b=(int)grand_total;
        double c=100*(grand_total-double(b));

        cout<<"\t GRAND TOTAL: \t"<<"\t $ "<<setprecision(2)<<(int)grand_total<<" & "<<(int)c<<" cents"<<endl;

        invoice.close();
        cout<<"\t Thanks for shopping with us and Have a good day ahead ! \t"<<endl;
        user_access::user();

    }
}
void user_access::Superuser_rights()
{
    string choice;
    cout<<left<<setw(100)<<"Type <1> to ADD a new product"<<endl;
    cout<<left<<setw(100)<<"Type <2> to MODIFY the product"<<endl;
    cout<<left<<setw(100)<<"Type <3> to DISPLAY all the products"<<endl;
    cout<<left<<setw(100)<<"Type <4> to LOGOUT of the superuser"<<endl;
    cin>>choice;
    if(choice=="1")
    {
        add_newProduct();
    }
    else if(choice=="2")
    {
        user_access::modify_product();
    }
    else if (choice=="3")
    {
        user_access::display_products();
    }
    else if(choice=="4")
    {
        cout<<left<<setw(100)<<"You are successfully logged out of the superuser"<<endl;
        user_access::user();

    }
    else
    {
        cout<<left<<setw(100)<<"Invalid entry ,Try again"<<endl;
        user_access::Superuser_rights();
    }
}
void user_access::add_newProduct()
{

    fstream store_database;
    store_database.open("supermarket_database.txt",ios::app);
    string price_string;
    string discount_value_string;
    string minimum_quantity_for_discount_string;
    if(store_database.is_open())
    {
        cout<<left<<setw(100)<<"Enter name of the new product "<<endl;
        cin>>name;
        cout<<left<<"Enter the new cost of one "<<name<<" in canadaian $"<<endl;
        cin>>price_string;
        price=stod(price_string);
        cout<<left<<setw(100)<<"Enter discount name: BUY1 , BUY2, BUY3, NoDiscout and so on"<<endl;
        cin>>discount_name;
        if(discount_name=="BUY1")
        {
            cout<<left<<setw(100)<<"Enter the minimum quantity required to avail discount"<<endl;
            cin>>minimum_quantity_for_discount_string;
            minimum_quantity_for_discount=stoi(minimum_quantity_for_discount_string);
            cout<<left<<"Enter the discount price for purchase of minimum " <<minimum_quantity_for_discount<<" quantities for "<<discount_name<<" coupon code"<<endl;
            cin>>discount_value_string;;             //this discount means ,if you buy three 3 quantities for 5 $,discount_value=$5
            discount_value=stod(discount_value_string);
            discount_value=(((price*minimum_quantity_for_discount)-(discount_value))/(price*minimum_quantity_for_discount));  //Here am converting it to discount value per item

        }
        else if(discount_name=="BUY2")
        {
            cout<<left<<setw(100)<<"Enter the minimum quantity required to avail discount"<<endl;
            cin>>minimum_quantity_for_discount_string;
            minimum_quantity_for_discount=stoi(minimum_quantity_for_discount_string);
            cout<<left<<"Enter the discount price for purchase of minimum " <<minimum_quantity_for_discount<<" quantities for "<<discount_name<<" coupon code"<<endl;
            cin>>discount_value_string;;             //this discount means ,if you buy three 3 quantities for 5 $,discount_value=$5
            discount_value=stod(discount_value_string);
            discount_value=(((price*minimum_quantity_for_discount)-(discount_value))/(price*minimum_quantity_for_discount));
        }
        else if(discount_name=="BUY3")
        {
            cout<<left<<setw(100)<<"Enter the minimum quantity required to avail discount"<<endl;
            cin>>minimum_quantity_for_discount_string;
            minimum_quantity_for_discount=stoi(minimum_quantity_for_discount_string);
            cout<<left<<"Enter the discount price for purchase of minimum " <<minimum_quantity_for_discount<<" quantities for "<<discount_name<<" coupon code"<<endl;
            cin>>discount_value_string;;             //this discount means ,if you buy three 3 quantities for 5 $,discount_value=$5
            discount_value=stod(discount_value_string);
            discount_value=(((price*minimum_quantity_for_discount)-(discount_value))/(price*minimum_quantity_for_discount));

        }
        else
        {

            cout<<left<<setw(100)<<"Enter the minimum quantity required to avail discount"<<endl;
            cin>>minimum_quantity_for_discount_string;
            minimum_quantity_for_discount=stoi(minimum_quantity_for_discount_string);
            cout<<left<<"Enter the discount price for purchase of minimum " <<minimum_quantity_for_discount<<" quantities for "<<discount_name<<" coupon code"<<endl;
            cin>>discount_value_string;;             //this discount means ,if you buy three 3 quantities for 5 $,discount_value=$5
            discount_value=stod(discount_value_string);
            if(minimum_quantity_for_discount==0)
            {
                discount_value=0;
            }
            else
            {
                discount_value=(((price*minimum_quantity_for_discount)-(discount_value))/(price*minimum_quantity_for_discount));
            }


        }

        store_database<<"\t"<<name<<"\t"<<price<<"\t"<<discount_name<<"\t"<<discount_value<<"\t"<<minimum_quantity_for_discount<<endl;
        store_database.close();
        string a;
        cout<<left<<setw(200)<<"Do you still want to add another new product :Type <Y> for Yes and <N> for No and Type <Exit> to bring back to main menu"<<endl;
        cin>>a;
        if(a=="Y"|| a=="y")
        {
            user_access::add_newProduct();
        }
        else if(a=="N"|| a=="n")
        {
            user_access::Superuser_rights();
        }
        else if(a=="Exit"||a=="EXIT"|| a=="exit")
        {
            user_access::user();
        }
        else
        {
            cout<<left<<setw(100)<<"Ivalid Entry and Try again and taking to Superuser Menu";
            user_access::Superuser_rights();
        }
    }
}
void user_access::modify_product()
{
    int flag=0;
    string a;
    string n;
    string price_string;
    string minimum_quantity_for_discount_string;
    string discount_value_string;
    fstream store_database;
    store_database.open("supermarket_database.txt",ios::in |ios ::app);
    if(store_database.is_open())
    {
        cout<<left<<setw(100)<<"Enter the name of product you want to modify"<<endl;
        cin>>n;

        fstream store_database2;
        store_database2.open("supermarket_database2.txt",ios ::app);
        if(store_database2.is_open())
        {
            while(store_database >> name >> price>> discount_name >> discount_value>> minimum_quantity_for_discount)
            {




                if(name!=n)
                {
                    store_database2<<"\t"<<name<<"\t"<<price<<"\t"<<discount_name<<"\t"<<discount_value<<"\t"<<minimum_quantity_for_discount<<endl;
                }
                else if(name==n)
                {
                    flag=1;
                    cout<<left<<setw(100)<<"You are good to modify the data"<<endl;
                    cout<<left<<setw(100)<<"Enter the new name"<<endl;
                    cin>>name;
                    cout<<left<<"Enter the new cost of one "<<name<<" in canadaian $"<<endl;
                    cin>>price_string;
                    price=stod(price_string);
                    cout<<left<<setw(100)<<"Enter the new discount name"<<endl;
                    cin>>discount_name;
                    cout<<left<<setw(100)<<"Enter the minimum quantity required to avail the discount"<<endl;
                    cin>>minimum_quantity_for_discount_string;
                    minimum_quantity_for_discount=stoi(minimum_quantity_for_discount_string);
                    cout<<left<<setw(200)<<"Enter the discount price in canadian $ (type in decimal if cost is 40 cents ,type 0.40 $) for purchase of minimum " <<minimum_quantity_for_discount<<" quantities for "<<discount_name<<" coupon code"<<endl;
                    cin>>discount_value_string;
                    discount_value=stod(discount_value_string);
                    if(minimum_quantity_for_discount==0)
                    {
                        discount_value=0;
                    }
                    else
                    {
                        discount_value=(((price*minimum_quantity_for_discount)-(discount_value))/(price*minimum_quantity_for_discount));
                    }

                    store_database2<<"\t"<<name<<"\t"<<price<<"\t"<<discount_name<<"\t"<<discount_value<<"\t"<<minimum_quantity_for_discount<<endl;

                }
            }

        }
        store_database2.close();
        store_database.close();
        remove("supermarket_database.txt");
        rename("supermarket_database2.txt","supermarket_database.txt");
        if(flag==0)
        {
            cout<<left<<setw(100)<<"The entered product is not available in our database"<<endl;
            cout<<left<<setw(100)<<"Try again"<<endl;
            user_access::modify_product();

        }

        cout<<left<<setw(200)<<"Do you still want to Modify the product :Type <Y> for Yes and <N> for No and Type <Exit> to bring back to main menu"<<endl;
        cin>>a;
        if(a=="Y"|| a=="y")
        {
            user_access::modify_product();
        }
        else if(a=="N"|| a=="n")
        {
            user_access::Superuser_rights();;
        }
        else if(a=="Exit"||a=="EXIT"|| a=="exit")
        {
            user_access::user();
        }
        else
        {
            cout<<left<<setw(100)<<"Ivalid Entry and Try again and taking to Superuser Menu";
            user_access::Superuser_rights();
        }

    }


}


void user_access::display_products()
{
    fstream store_database;
    store_database.open("supermarket_database.txt",ios::in);
    if(store_database.is_open())
    {
        while(store_database >> name >> price>> discount_name >> discount_value>> minimum_quantity_for_discount)
        {
            cout<<"\t Product name: "<<setw(10)<<name<<"\t Cost of one item: "<<setw(5)<<"$"<<setprecision(2)<<price<<"\t Discount Available: "<<setw(15)<<discount_name<<"\t %age Discount: "<<setw(5)<<setprecision(2)<<100*discount_value<<"\t Minimum quantity to get discount: "<<setw(5)<<minimum_quantity_for_discount<<endl;
        }
        store_database.close();
    }
    user_access::Superuser_rights();
}
int main()
{
    while(1)
    {
        user_access obj1;
        obj1.user();
    }





    return 0;
}
