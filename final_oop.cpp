#include <iostream>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
int counter=0;
using namespace std;
void clrscr(){
	system("@cls||clear");fflush(stdin);
}
class hitung{
	friend void set_nama(hitung&f, string name)
	{
		f.nama=name;
	}
	protected:
		int score;
		string nama;
		int correct_score;
		int wrong_score;
		
	public:
		hitung(){
			score=0;
			correct_score=0;
			wrong_score=0;
			nama=" ";
		}
		~hitung(){
			cout<<"Thank You For Using This Program ";
		}
		void set_score(int score){
			this->score=score;
		}	
		int get_score(){
			return score;
		}
		string get_nama()
		{
			return nama;
		}
		int get_wrong()
		{
			return wrong_score;
		}
		int get_correct()
		{
			return correct_score;
		}
		int get_counter()
		{
			return counter;
		}
};
const char newline='\n';
const char tab='\t';
/*class save_score
{
	public:
	ofstream outfile;
	outfile.open("score.txt",std::ios_base::app);
	outfile<<score;
	outfile<<name;
};
*/
class stage1 : public hitung{
	protected:
		int stage1_score;
		int a,b,c;
		int hasil_compare,hasil_user;
		const int MAX_TIME_LIMIT=12000;
	public:
		stage1(){
			stage1_score=0;
			a=0,b=0,c=0;
		}
		~stage1(){
			cout<<"destructor stage";
		}
		inline void acak_dan_hitung(int a)
		{
			long start_time=clock();
			int d,e,f,g;
			srand(time(NULL));
			b=(rand()%6+2);//random angka
			c=(rand()%4+6);//random angka
			d=(rand()%2);
			int& reference=d;
			e=(rand()%2);
			f=(rand()%2);
			g=(rand()%2);
			if(reference==1)
			{	
				if(e==1)
				{	
					if(f==1)
					{										
						cout<<"Soal + \n";
						cout<< a<<" + "<<b<< " = ";
						cin>>hasil_user;
						hasil_compare=a+b;
					}
					else
					{
						cout<<" Soal + -\n";
						cout<< a<<" + "<<b<<" - "<<c<<" = ";
						cin>>hasil_user;
						hasil_compare=a+b-c;
					}	
				}
				else
				{
					cout<<" Soal + + \n";
					cout<< a<<" + "<<b<<" + "<<c<<" = ";
					cin>>hasil_user;
					hasil_compare=a+b+c;
				}
			}
			else
			{
				if(e==1)
				{
					f=(rand()%2);
					if(f==1)
					{
						cout<<" Soal -\n";
						cout<< a<<" - "<<b<< " = ";
						cin>>hasil_user;
						hasil_compare=a-b;
					}
					else
					{			
						cout<<" Soal - + \n";
						cout<< a<<" - "<<b<<" + "<<c<<" = ";
						cin>>hasil_user;
						hasil_compare=a-b+c;
					}
				}
				else
				{
					cout<<" Soal - -\n ";
					cout<< a<<" - "<<b<<" - "<<c<<" = ";
					cin>>hasil_user;
					hasil_compare=a-b-c;
				}
			}
			long end_time=clock();
			if( end_time - start_time > MAX_TIME_LIMIT)
  			{ 
      			cout << "Time limit exceeded\n"; 
  			}
			else
			{
				if(hasil_user==hasil_compare)
				{
					clrscr();
					cout<<" Your Answer is Correct";
					stage1_score=10;
					score=score+stage1_score;
					correct_score++;
				}
				else
				{
					clrscr();
					cout<<" Your Answer is Wrong !!!";
					wrong_score++;
					// reset scrore dan save score
				}
				counter++;	
			}	
		}
		inline void acak_dan_hitung(int a,int b,int c)
		{
			long start_time=clock();
			int random1,random2,random3;
			srand(time(NULL));
			random1=(rand()%2);
			random2=(rand()%2);
			random3=(rand()%2);
			if(random1==1)
			{
				if(random2==1)
				{
					cout<<"Soal Perkalian\n";
					cout<< a<<" * "<< b<<" = ";
					cin>>hasil_user;
					hasil_compare=a*b;
				}
				else
				{
					cout<<"Soal Pembagian [ Rata-Rata Bawah] : ";
					cout<<"Soal Pembagian\n";
					cout<< a<<" / "<< b<<" = ";
					cin>>hasil_user;
					hasil_compare=a/b;
				}
			}
			else
			{
				if(random2==1)
				{
					cout<<"Soal Modulus \n";
					cout<< a<<" % "<< b<<" = ";
					cin>>hasil_user;
					hasil_compare=(a%b);
				}
				else
				{
					cout<<"Soal Bonus ";
					cout<< a<<" + "<< b<<" * "<<c<<" = ";
					cin>>hasil_user;
					hasil_compare=(a+(b*c));
				}
			}
			long end_time=clock();
			if( end_time - start_time > MAX_TIME_LIMIT)
  			{ 
      			cout << "Time limit exceeded\n"; 
  			}
  			else
			{
				if(hasil_user==hasil_compare)
				{
					clrscr();
					cout<<" Your Answer is Correct";
					stage1_score=20;
					score=score+stage1_score;
					correct_score++;
				}
				else
				{
					clrscr();
					cout<<" Your Answer is Wrong !!!";
					wrong_score++;
				}
				counter++;
			}
		}
		int get_stage1_score()
		{
			return stage1_score;
		}
};
class login{
	protected:
		string login_id;
		string login_pw;
	public :
		login(){
			login_id=" ";
			login_pw=" ";
		}
		void SetData(string user,string pass){
			this->login_id=user;
			this->login_pw=pass;
		}
		string get_user(){
			return login_id;
		}
		string get_pass(){
			return login_pw;
		}
		virtual void cek(){}
};

class CekLogin: public login{
	public:
		void cek(){
		    cout<<"Berhasil Login";
		}
};

class save
{
	
};

template <class T> 
class A{
	public:
		T data;
};

int main()
{
	stage1 angka;
	login *pointer;
	pointer=new CekLogin();
	string user,pass;
	do{
		cout<<newline<<newline<<"Masukkan ID : "; 
		cin>>user;
    	cout<<"Masukkan Pass : "; 
		cin>>pass;
		pointer->SetData(user,pass);
	}while(pointer->get_user()!="siap" || pointer->get_pass()!="siap");
	CekLogin cek_login;
	pointer= &cek_login;
	pointer->cek();
	getch();
	int pilihan,pilihan1,age;
	string name_awal,name_akhir,name;
	do{
		clrscr();
		cout<<endl<<" Welcome To JFW Calculate Program "<<newline;
		cout<<"1. Mulai Perhitungan "<<newline;
		cout<<"2. Peraturan "<<newline;
		cout<<"3. Simpan Score"<<newline;
		cout<<"4. Show Score"<<newline;
		cout<<"5. Exit"<<newline;
		do{
			cout<<">> Input Your Choice : ";
			cin>>pilihan;
		}while((pilihan<1)||(pilihan>5));
		switch(pilihan)
		{
			case 1 : 
			{
				clrscr();
				do{
					cout<<"Please Insert Name[3-30] : ";
					getline(cin,name);
				}while((name.length()<3)||(name.length()>30));
				A<string>pertama;
				pertama.data=name;
				A<int>kedua;
   				cout<<"Please Input Your Age: ";
   				cin>>age;
   				kedua.data=age;
				do{
					clrscr();
					cout<<"Hi, "<<left<<setw(30)<<setfill('.')<<pertama.data<<newline;
					cout<<"Your Age "<<kedua.data<<newline;
					cout<<"Welcome to Counting Games"<<newline;
					cout<<"Your Score is : "<<angka.get_score()<<endl;
					cout<<"You Already Answer "<<angka.get_correct()<<" Correct Answer and "<<angka.get_wrong()<<" Wrong Score"<<newline<<newline;
					cout<<"Pilih Soal : \n";
					cout<<"1. Tambah-Tambahan\n";
					cout<<"2. Perkalian\n";
					cout<<"3. Back\n";
					do{
						cout<<">>Choose : ";
						cin>>pilihan1;
				}while((pilihan1<1)||(pilihan1>3));
				switch(pilihan1)
				{
					case 1 : 
					{
						clrscr();
						int a=(rand()%5+3);//random angka
						angka.acak_dan_hitung(a);
						getch();
						break;
					}
					case 2 : 
					{
						clrscr();
						int a=(rand()%3+5);
						int b=(rand()%3+4);
						int c=(rand()%3);
						angka.acak_dan_hitung(a,b,c);
						getch();
						break;
						//soal perkalian
					}
				}
			//	angka.stage1_hitung();
			//	angka.scoring();
			//	cout<<"score anda sekarang:"<<angka.get_score();
			//	break;
				}while(pilihan1!=3);	
			}
			case 2:
			{
				//peraturan
				break;
			}
			case 3 : 
			{	// save score
				clrscr();
				std::ofstream outfile;
				outfile.open("score.txt",std::ios_base::app);
				if(counter==1)
				{
					outfile<<angka.get_nama()<<tab<<tab;
					outfile<<angka.get_score();
					outfile<<"\n";
				}
				else if(counter>1)
				{
					outfile<<angka.get_nama()<<tab;
					outfile<<angka.get_score();
					outfile<<"\n";
				}
				hitung a;
				getch();
				break;
				//save score
			}
			case 4 :
			{
				clrscr();
				std::ifstream infile("score.txt");
				if(infile.is_open())
				{
					cout<<" +----------+---------+"<<endl;
					cout<<" |  Name    |  Score  | "<<endl;
					cout<<" +----------+---------+"<<endl;
					std::string line;
					while(getline(infile,line))
					{
						cout<<" | "<<line.c_str()<<"    | ";
						cout<<"\n";
					}
					cout<<" +----------+---------+"<<endl;
					infile.close();
				}
				getch();
				break;	//display score
			}	
		}
	}while(pilihan!=5);
	cout<<"THANK YOU";
}
