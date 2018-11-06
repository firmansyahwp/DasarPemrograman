#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;
ofstream struk;

//variabel 
char 	bantu[100], pilih2,	a;	 
int     var_harga, total=0;
int 	batas,	pilih, transfer;
char    nama[25];
string 	cari;

//time
time_t now = time(0);
char* dt = ctime(&now);;

//record data
struct admin {
	int  pin, nbayar;
	int  rek	;
}; admin adm[20];

struct pulsa {
   string   tipe;
   int      bayar;
   int      kode;
   string   nohp[13];
} ; pulsa pls[20];

//daftar harga
void harga() {
	cek:
	cout << "_______________________\n";
	cout << "| Daftar Operator     |\n";
	cout << "-----------------------\n";
	cout << "| 1. Telkomsel        |\n";
	cout << "| 2. Axis             |\n";
	cout << "| 3. Indosat          |\n";
	cout << "| 4. three            |\n";
	cout << "| 5. kembali ke menu  |\n"; 
	cout << "-----------------------\n";
	cout << "_______________________\n";
	cout << "* Pilih operator : ";
	cin  >> var_harga;
	
	if (var_harga == 1) {
	cout << " ____________________________________________ \n";
	cout << " | nama operator | Nominal   |    harga      | \n";
	cout << " -------------------------------------------- \n";
	cout << " |   Telkomsel   |  5000     |  Rp5.500,00   | \n";
	cout << " |               |  10000    |  Rp11.000,00  | \n";
	cout << " |               |  20000    |  Rp21.500,00  | \n";
	cout << " |               |  50000    |  Rp52.000,00  | \n";
	cout << " |               |  100000   |  Rp102.000,00 | \n";	
	cout << " -------------------------------------------- \n"; 
    } else if (var_harga == 2) {
    cout << " ____________________________________________ \n";
	cout << " | nama operator | Nominal   |    harga      | \n";
	cout << " -------------------------------------------- \n";
	cout << " |   AXIS        |  5000     |  Rp5.300,00   | \n";
	cout << " |               |  10000    |  Rp10.300,00  | \n";
	cout << " |               |  20000    |  Rp20.500,00  | \n";
	cout << " |               |  50000    |  Rp51.000,00  | \n";
	cout << " |               |  100000   |  Rp101.000,00 | \n";	
	cout << " -------------------------------------------- \n"; 
	} else if (var_harga == 3) {
	cout << " ____________________________________________ \n";
	cout << " | nama operator | Nominal   |    harga      | \n";
	cout << " -------------------------------------------- \n";
	cout << " |   Indosat     |  5000     |  Rp6.000,00   | \n";
	cout << " |               |  10000    |  Rp12.000,00  | \n";
	cout << " |               |  20000    |  Rp22.500,00  | \n";
	cout << " |               |  50000    |  Rp53.000,00  | \n";
	cout << " |               |  100000   |  Rp104.000,00 | \n";	
	cout << " -------------------------------------------- \n"; 	
	} else if ( var_harga == 4) {
	cout << " ____________________________________________ \n";
	cout << " | nama operator | Nominal   |    harga      | \n";
	cout << " -------------------------------------------- \n";
	cout << " |   Three       |  5000     |  Rp5.100,00   | \n";
	cout << " |               |  10000    |  Rp10.100,00  | \n";
	cout << " |               |  20000    |  Rp20.100,00  | \n";
	cout << " |               |  50000    |  Rp51.000,00  | \n";
	cout << " |               |  100000   |  Rp101.000,00 | \n";	
	cout << " -------------------------------------------- \n"; 
	} 
	else if ( var_harga == 5 ) {
		goto end;
	}
	 else {
	cout << " Kesalahan Input !! \n" ;
	}
	goto cek;
	end:
	cout << "\n Press any key to back.... ";
	getch();
}

//main menu 1
void menu(){ 
	system("cls");	
	cout << "\n ___________________________________________ "; 
	cout << "\n |============ Team Five Cell =============| ";
	cout << "\n |=========isi ulang pulsa online==========| ";
	cout << "\n ------------------------------------------- "; 
	cout << "\n | 1. Pengisian Data                       |";
	cout << "\n | 2. Info Harga dan Operator              |";
	cout << "\n | 3. Pembayaran                           |";
	cout << "\n | 4. Riwayat Transaksi                    |";
	cout << "\n | 5. Cari Data                            |";
	cout << "\n | 0. keluar                               |";
	cout << "\n ------------------------------------------- "; 
	cout << "\n ___________________________________________ "; 
	cout << "\n * Masukkan pilihan : ";
	cin  >> pilih;
	system("cls");
}
	
//input data
void inputdata() {
		cout << "  \t  __________________________________________ ";	
		cout << "\n\t |================INPUT DATA================| ";
		cout << "\n\t  ------------------------------------------ ";
		
		cin.ignore();  // memberikan hak akses untuk ijin input
		cout <<"\n\t Nama Konsumen    : "; 
		cin.getline(nama,25);
		cout <<"\t Banyak pengisian : "  ;    cin >> batas; 
		cout << "\t_______________________\n";
		cout << "\t| Daftar Operator     |\n";
		cout << "\t-----------------------\n";
		cout << "\t| -. Telkomsel        |\n";
		cout << "\t| -. Axis             |\n";
		cout << "\t| -. Indosat          |\n";
		cout << "\t| -. three            |\n";
		cout << "\t-----------------------\n";
	
	for ( int i=1; i<= batas; i++) {
		salah:
		cout << "\n\t #pengisian ke -" << i ;
		cout <<"\n\t Masukan Nama Operator (misal three)  : ";    cin>> pls[i].tipe;
		hp:
		cout <<"\t Masukan Nomor HP                     : ";      cin>>pls[i].nohp[i];
		cout<<"\t+-------------+--------------+"<<endl;
		cout<<"\t|   NOMINAL   | KODE NOMINAL |"<<endl;
		cout<<"\t+-------------+--------------+"<<endl;
		cout<<"\t| Rp 5000     |       5      |"<<endl;
		cout<<"\t| Rp 10000    |       10     |"<<endl;
		cout<<"\t| Rp 20000    |       20     |"<<endl;
		cout<<"\t| Rp 50000    |       50     |"<<endl;
		cout<<"\t| Rp 100000   |       100    |"<<endl;
		cout<<"\t+-------------+--------------+"<<endl;
		cout<<endl;
		cout <<"\t Masukan kode Nominal       : ";
		cin.ignore();
		cin >>pls[i].kode;	
		cout<<endl;	

		if (pls[i].kode==5             && pls[i].tipe=="TELKOMSEL" | pls[i].tipe=="telkomsel"  ) {pls[i].bayar = 5500; }
			else if (pls[i].kode==10   && pls[i].tipe=="TELKOMSEL" | pls[i].tipe=="telkomsel"  ) {pls[i].bayar = 11000; }
			else if (pls[i].kode==20   && pls[i].tipe=="TELKOMSEL" | pls[i].tipe=="telkomsel"  ) {pls[i].bayar = 21500; }
		    else if (pls[i].kode==50   && pls[i].tipe=="TELKOMSEL" | pls[i].tipe=="telkomsel"  ) {pls[i].bayar = 52000; }
		    else if (pls[i].kode==100  && pls[i].tipe=="TELKOMSEL" | pls[i].tipe=="telkomsel"  ) {pls[i].bayar = 102000;}
			else if (pls[i].kode==5    && pls[i].tipe=="AXIS" | pls[i].tipe=="axis"  ) 			 {pls[i].bayar = 5300; }
			else if (pls[i].kode==10   && pls[i].tipe=="AXIS" | pls[i].tipe=="axis"  ) 	    	 {pls[i].bayar = 10300; }
			else if (pls[i].kode==20   && pls[i].tipe=="AXIS" | pls[i].tipe=="axis"  ) 			 {pls[i].bayar = 20500; }
		    else if (pls[i].kode==50   && pls[i].tipe=="AXIS" | pls[i].tipe=="axis"  )	 		 {pls[i].bayar = 51000; }
		    else if (pls[i].kode==100  && pls[i].tipe=="AXIS" | pls[i].tipe=="axis"  ) 			 {pls[i].bayar = 101000; }
			else if (pls[i].kode==5    && pls[i].tipe=="INDOSAT" | pls[i].tipe=="indosat"  ) 	 {pls[i].bayar = 6000; }
			else if (pls[i].kode==10   && pls[i].tipe=="INDOSAT" | pls[i].tipe=="indosat"  ) 	 {pls[i].bayar = 12000; }
			else if (pls[i].kode==20   && pls[i].tipe=="INDOSAT" | pls[i].tipe=="indosat"  ) 	 {pls[i].bayar = 22500; }
		    else if (pls[i].kode==50   && pls[i].tipe=="INDOSAT" | pls[i].tipe=="indosat"  ) 	 {pls[i].bayar = 53000; }
		    else if (pls[i].kode==100  && pls[i].tipe=="INDOSAT" | pls[i].tipe=="indosat"  ) 	 {pls[i].bayar = 104000;}
			else if (pls[i].kode==5    && pls[i].tipe=="THREE" | pls[i].tipe=="three"  ) 	 	 {pls[i].bayar = 5100; }
			else if (pls[i].kode==10   && pls[i].tipe=="THREE" | pls[i].tipe=="three"  ) 		 {pls[i].bayar = 10100; }
			else if (pls[i].kode==20   && pls[i].tipe=="THREE" | pls[i].tipe=="three"  ) 		 {pls[i].bayar = 20100; }
		    else if (pls[i].kode==50   && pls[i].tipe=="THREE" | pls[i].tipe=="three"  ) 		 {pls[i].bayar = 51000; }
		    else if (pls[i].kode==100  && pls[i].tipe=="THREE" | pls[i].tipe=="three"  ) 		 {pls[i].bayar = 101000; }
			else  { cout << "\t Maaf,Terdapat Kesalahan input !"; 
					cout <<"\n\t Mohon periksa kembali pada jenis operator atau kode nominal \n";	goto salah;}		
	}
	cout << "\t Kembali ke Menu untuk melanjutkan dan mengetahui info pembayaran";
	for(int i=1;i<=batas;i++){
		total=total + pls[i].bayar;
	}
}

//info pembayaran
void info() {
		cout << "\n\t | Nama            : " <<nama;
        for(int j=1; j<=batas; j++) {
            cout << "\n\t  __________________________________________ ";	
			cout << "\n\t |==============INFO PEMBELIAN==============| ";
			cout << "\n\t  ------------------------------------------ ";
	        cout << "\n\t | Nomor HP        : "	<<pls[j].nohp[j];
	        cout << "\n\t | Nama Operator   : "	<<pls[j].tipe;
	        cout << "\n\t | Nominal         : "	<<pls[j].kode;    
			cout << "\n\t | Date            : " <<dt << endl;     
	        cout << "  \t  ------------------------------------------ \n";  
        };
}

//menu transfer
void transfer1() {
	cout << endl;
	cout <<"Nama : "				  <<nama<<endl;
	cout <<"---------------- FIVE CELL -------------------"<<endl;
	cout <<"+----+---------+------------+-----------------+\n";
	cout <<"| No | nominal | operator   |       bayar     |\n";
	cout <<"+----+---------+------------+-----------------+\n";
																				
	for(int i=1; i<=batas;i++) {
		cout <<"| "<<i<<"  |";
		cout <<"    "<<pls[i].kode;
		cout <<"\t "<<pls[i].tipe;
		cout <<"\t\tRp"<<pls[i].bayar;
		cout << endl;
	}

	cout << "+----+---------+------+\n";
	cout << "| Total bayar  : Rp"; 
	cout << total;
	cout << endl;
	cout << "+----+---------+------+\n";
	cout << " Silahkan Transfer sebesar   : Rp";
	cout << total+7;
	cout << "\n Atas nama                   : PT.Five cell indo";
	cout << "\n No. rek                     : 12345,-";
	cout << "\n Bank BRI";
	cout << "\n\n Jangan mengabaikan pada 2 angka terakhir";
	cout << "\n 07 merupakan identitas \n Di mohon untuk transfer senilai jumlah yang tercantum";
	cout << endl;
	
	coba :
	cout << "\n\t ___________________________________________ "; 
	cout << "\n\t |=============== Transaksi ================| ";
	cout << "\n\t ------------------------------------------- "; 
	cout << "\n\t | 1. Transfer sekarang                     |";
	cout << "\n\t | 2. Transfer Nanti                        |";
	cout << "\n\t | 3. Keluar                                |";
	cout << "\n\t ------------------------------------------- "; 
	cout << "\n\t Masukkan pilihan : ";
	cin  >> transfer;
	
	switch (transfer){
		case 1 : { 
				cout << "\n Masukkan Jumlah Yang akan transfer : ";  
				cin  >> adm[20].nbayar;
				cout << " Masukkan pin anda                  : ";
				cin  >> adm[20].pin;
				cout << " Masukkan rekening tujuan           : ";
				cin  >> adm[20].rek;
				
				if (adm[20].nbayar >= total+7 && adm[20].rek ==12345){
					cout << "\n Anda mentransfer sebesar   : Rp";
					cout << adm[20].nbayar;
					cout << "\n Atas nama                  : PT.Five cell indo";
					cout << "\n No. rek                    : 12345,";
					cout << "\n ingin melanjutkan transaksi ? (Y/T) : ";
					cin  >> a;
					
					if (a=='Y' || a=='y') {
						cout << "\n Selamat !! Transaksi berhasil. \n";
						cout << " Permintaan anda akan segera diproses \n\n";
					} else {
						goto coba;
					}
				} else if (adm[20].nbayar <= total+7 && adm[20].rek ==12345  ){
					cout <<"\n mohon cek kembali total harga. terima kasih \n\n";
					goto coba;
				} else {
					cout <<" mohon periksa kembali no.rek tujuan \n\n";
					goto coba;
				}
				//membuat struct
				struk << endl;
				struk <<"\nNama : "				  <<nama<<endl;
				struk <<"---------------- FIVE CELL -------------------"<<endl;
				struk <<"+----+---------+------------+-----------------+\n";
				struk <<"| No | nominal | operator   |       bayar     |\n";
				struk <<"+----+---------+------------+-----------------+\n";
		
					for(int i=1; i<=batas;i++) {
						struk <<"| "<<i<<"  |";
						struk <<"     "<<pls[i].kode;
						struk <<"\t  "<<pls[i].tipe;
						struk <<"\t\t Rp"<<pls[i].bayar;
						struk <<endl;
					}	
				struk << endl;
				struk << "+----+---------+------+\n";
				struk << "| Tagihan   : Rp"; 
				struk << (	total+7);
				struk << endl;
				struk << "+----+---------+------+\n";
				struk << "+----+---------+------+\n";
				struk << "| Total bayar  : Rp"; 
				struk << adm[20].nbayar;
				struk << endl;
				struk << "+----+---------+------+\n";
				struk << "+----+---------+------+\n";
				struk << "| Kembalian  : Rp"; 
				struk << adm[20].nbayar-total;
				struk << endl;
				struk << "+----+---------+------+\n";
				struk << endl;
				struk << " Permintaan segera di proses.\n Status LUNAS ";
				struk <<"\n "<<dt << endl;
			break;
		}
		case 2 : {
				cout << "\n Mohon segera transfer dalam waktu 24 jam. Terima kasih \n\n";
				//struk suspend
				struk << endl;
				struk <<"\nNama : "				  <<nama<<endl;
				struk <<"---------------- FIVE CELL -------------------"<<endl;
				struk <<"+----+---------+------------+-----------------+\n";
				struk <<"| No | nominal | operator   |       bayar     |\n";
				struk <<"+----+---------+------------+-----------------+\n";
		
					for(int i=1; i<=batas;i++) {
						struk <<"| "<<i<<"  |";
						struk <<"    "<<pls[i].kode;
						struk <<"\t " <<pls[i].tipe;
						struk <<"\t\tRp"<<pls[i].bayar;
						struk <<endl;
					}		
				struk <<endl;
				struk << "+----+---------+------+\n";
				struk << "| Tagihan   : Rp"; 
				struk <<(total+7);
				struk << endl;
				struk << "+----+---------+------+\n";
				struk <<"\n Permintaan suspend \n Belum melakukan transfer ";
				struk <<"\n "<<dt << endl;
				cout  <<endl;
			break;
		}
		case 3 : { 
			break;
		}
		default : {
			cout << "\n\t Mohon periksa kembali,terdapat kesalahan input ! \n";
			goto coba;
		}
	}
}

//fungsi utama
int main () {
	do { 
	a:
	menu();
	switch (pilih) {
	case 1 :{ inputdata();
		break;
		}
	case 2 :{ harga();
			  goto a;
		break;
		}	
	case 3 :{ 
		if ( batas==0){
			cout <<" Maaf,belum ada data terinput !";
		} else {
			struk.open("struk.doc",ios::app);
			transfer1();
			struk.close();
		}
		break;
		}
	case 4 :{ 
		if ( batas==0){
			cout <<" Maaf,belum ada data terinput !";
		} else {
			ifstream cari;
			cari.open("struk.doc");
				while(cari) {
				cari.getline(bantu,1000);
				cout <<bantu <<endl;
				}
				cari.close();	
			}
		break;
	}
	case 5 :{ 
		if ( batas==0){
			cout <<" Maaf,belum ada data terinput !";
		}else {
		cout << "\n\t Masukkan Nama operator untuk Pencarian daata : ";
		cin >> cari;
		
		for(int i=1; i<=batas; i++){
			if (cari == pls[i].tipe){
				cout << "\n\t | Nama            : " <<nama;
	            cout << "\n\t  __________________________________________ ";	
				cout << "\n\t |==============INFO PEMBELIAN==============| ";
				cout << "\n\t  ------------------------------------------ ";
		        cout << "\n\t | Nomor HP        : "	<<pls[i].nohp[i];
		        cout << "\n\t | Nama Operator   : "	<<pls[i].tipe;
		        cout << "\n\t | Nominal         : "	<<pls[i].kode;    
				cout << "\n\t | Date            : " <<dt << endl;     
		        cout << "  \t  ------------------------------------------ \n";  
			} else {
				cout << " kosong ";
			}
		}
		}
		break;
	}
	case 0 :{ goto akhir;
		break;
		}
	default : {
			cout << "\n Maaf, Terdapat kesalahan dalam inputan! ";
			cout << "\n press any key to continue..."; 
			getch();
		}
	}		
	end:
	cout << "\n\n ingin kembali ke menu ?  (Y/T) ?  : ";
	cin  >> pilih2;
} while (pilih2=='y' || pilih2=='Y');
	akhir:
	cout << "\n TERIMA KASIH TELAH MENGGUNAKAN APILIKASI DARI FIVE CELL \n\t SEMOGA HARI ANDA MENYENANGKAN\n";
	getch();
	return 0;
}          

