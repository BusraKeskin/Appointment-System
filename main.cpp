/*akademisyen.txt
1234 Vasif Nabiyev Bilgisayar 12345@abc.com 0548697 Prof.Dr
4321 Zafer Yavuz   Bilgisayar 4321@bca.com  0548664 Og.Grv
*/
/*randevu.txt
289949 1234 01.11.2018 10.10 10.11
289949 1234 12.12.2018 10.10 10.11
330186 1234 12.11.2018 10.10 11.10
330186 1234 01.11.2018 10.10 10.11
289949 1234 12.12.2018 09.00 09.20
*/

/*ogrenci.txt
123456 Ferdi Besli Bilgisayar 2014 ferdi@abc.com 905051234567
123465 adam Besli Bilgisayar 2014 ferdi@abc.com 905051234567
323456 ole Besli Bilgisayar 2014 ferdi@abc.com 905051234567
423456 yle Besli Bilgisayar 2014 ferdi@abc.com 905051234567
289949 gio Besli Bilgisayar 2014 ferdi@abc.com 905051234567
330186 busra Besli Bilgisayar 2014 ferdi@abc.com 905051234567
*/

//Büþra Keskin - 330186 (2.Öðretim) - 3.Arasýnav Zorunlu Ödev
#include <iostream>
#include<fstream>
#include <stdlib.h> 
#define AKADEMISYEN 5
#define OGRENCI 20
#define MAX 1000

using namespace std;

int randevu_sayisi=0; //randevularýn toplam sayýsýný okurken sayýp güncelliiyoruz

class ContactInfo{
  public:
  
  string getAd(){return ad;}

  void setAd(string s){
    ad = s;
    }


  string getSoy(){return soy;}
  void setSoy(string z){
    soy = z;
    }
  string getEposta(){return e_posta;}
  void setEposta(string p){
    e_posta = p;
  }
  string getTelefon(){return telefon;}
  void setTelefon(string t){
    telefon = t;

  }
  string ad;
  string soy;
  string e_posta;
  string telefon;
};

class Akademisyen:public ContactInfo{ //Inheritance

  public:
  
 
  string getSicil(){
    return sicil;
  }
  void setSicil(string b){
     sicil = b;
  }
  string getDal(){
    return ana_dal;
  }
  void setDal(string c){
    ana_dal = c;

  }
  string getUnvan(){
    return unvan;
  }
  void setUnvan(string d){
    unvan = d;
  }
  private:
  string ana_dal;
  string unvan;
  string sicil;
};

class Ogrenci:public ContactInfo{ //Inheritance

  public:
  
  string getNo(){
    return ogr_no;
  }
  void setNo(string a){
     ogr_no=a;
  }

  string getBolum(){
    return bolum;
  }
  void setBolum(string b){
    bolum = b;
  }

  string getYil(){
    return g_yili;
  }
  void setYil(string c){
    g_yili = c;
  }

  private:
  string ogr_no;
  string bolum;
  string g_yili;
};

class Randevu{
  public:
   string getTarih(){
    return tarih;
  }
  void setTarih(string t){
    tarih = t;

  }
  string getBaslangic(){
    return baslangic_s;
  }
  void setBaslangic(string bs){
    baslangic_s = bs;

  }
  string getBitis(){
    return bitis_s;
  }
  void setBitis(string bt){
    bitis_s = bt;

  }
 
  void setGun(int g){
    gun = g;
  }
  void setAy(int a){
    ay = a;
  }
  void setYil(int y){
    yil = y;
  }
  int getGun(){
    return gun;
  }
  int getAy(){
    return ay;
  }
  int getYil(){
    return yil;
  }

  void setSaatStart(int s){
    satart_saat = s;
  }
  void setSaatEnd(int s){
    end_saat = s;
  }
  void setDakikaStart(int d){
    satart_dakika = d;
  }
  void setDakikaEnd(int d){
    end_dakika = d;
  }
  int getSaatStart(){
    return satart_saat;
  }
  int getSaatEnd(){
    return end_saat;
  }
  int getDakikaStart(){
    return satart_dakika;
  }
  int getDakikaEnd(){
    return end_dakika;
  }
  void colision(int i,ifstream &dosya);

  void setAkademisyen(Akademisyen ak){//Randevu dizisine akademisyenleri kopyalýyorum
    akademisyen.setSicil(ak.getSicil());
    akademisyen.setDal(ak.getDal());
    akademisyen.setUnvan(ak.getUnvan());
    akademisyen.setAd(ak.getAd());
    akademisyen.setSoy(ak.getSoy());
    akademisyen.setEposta(ak.getEposta());
    akademisyen.setTelefon(ak.getTelefon());
  }

  string getAkademisyen(){
    return akademisyen.getSicil();
  }
  void setOgrenci(Ogrenci ogr){//Randevu dizisine öðrencileri kopyalýyorum
    ogrenci.setNo(ogr.getNo());
    ogrenci.setAd(ogr.getAd());
    ogrenci.setSoy(ogr.getSoy());
    ogrenci.setYil(ogr.getYil());
    ogrenci.setEposta(ogr.getEposta());
    ogrenci.setTelefon(ogr.getTelefon());
    ogrenci.setBolum(ogr.getBolum());
  }

  string getOgrenci(){
    return ogrenci.getNo();
  }
  Ogrenci getOgrObj(){
    return ogrenci;
  }

  void resetOgrenci(){
    ogrenci.setNo("");
    ogrenci.setAd("");
    ogrenci.setSoy("");
    ogrenci.setYil("");
    ogrenci.setEposta("");
    ogrenci.setTelefon("");
    ogrenci.setBolum("");
  }

  private:
  //Composition
  Akademisyen akademisyen;
  Ogrenci ogrenci;

  string tarih;
  int gun;
  int ay;
  int yil;
  string baslangic_s;
  string bitis_s;

  int satart_saat;
  int end_saat;
  int satart_dakika;
  int end_dakika;
};

void read_a(Akademisyen akademisyen []){//Dosyadan akademisyenleri okuyup diziye atýyorum

  string dosyain = "akademisyen.txt";
	ifstream dosya;
  dosya.open(dosyain.c_str());
  string sicil, ana_dal, unvan;

  for(int i=0;i<AKADEMISYEN;i++){
    if( dosya.eof() ) break;
    dosya>>sicil;
    akademisyen[i].setSicil(sicil);
    dosya>> akademisyen[i].ad;
    dosya>> akademisyen[i].soy;
    dosya>> ana_dal;
    akademisyen[i].setDal(ana_dal);
    dosya>> akademisyen[i].e_posta;
    dosya>> akademisyen[i].telefon;
    dosya>>unvan;
    akademisyen[i].setUnvan(unvan);
  }
  dosya.close();
}

void read_o(Ogrenci ogrenci[]){//Dosyadan öðrencileri okuyup diziye atýyorum

  string no, g_yili, bolum, temp;
  string dosyain = "ogrenci.txt";
	ifstream dosya;

  dosya.open(dosyain.c_str());
  
  for(int i=0;i<OGRENCI;i++){
    if( dosya.eof() ) break;
    dosya>>no;
    ogrenci[i].setNo(no);
    dosya>> ogrenci[i].ad;
    dosya>> ogrenci[i].soy;
    dosya>>bolum;
    ogrenci[i].setBolum(bolum);
    dosya>> g_yili;
    ogrenci[i].setYil(g_yili);
    dosya>> ogrenci[i].e_posta;
    dosya>> ogrenci[i].telefon;
  }
  dosya.close();
}

void date_and_time_to_int(Randevu r){//Çakýþmayý kontrol etmek için int'lere ayýrýyorum
  string t = r.getTarih(); //"12.12.2018";
  string s = r.getBaslangic();//baslangic saati
  string e = r.getBitis();
  
  r.setGun(atoi(t.substr(0,2).c_str()));
  r.setAy(atoi(t.substr(3,2).c_str()));
  r.setYil(atoi(t.substr(6,4).c_str()));

  r.setSaatStart(atoi(s.substr(0,2).c_str()));
  r.setDakikaStart(atoi(s.substr(3,2).c_str()));

  r.setSaatEnd(atoi(e.substr(0,2).c_str()));
  r.setDakikaEnd(atoi(e.substr(3,2).c_str()));

}

//Dosyadan randevularý okuyup diziye atýyorum
void read_r(Randevu randevu[], Akademisyen ak[], Ogrenci ogr[]){

  string dosyain = "randevu.txt";
  int x=-1;
	ifstream dosya;
  dosya.open(dosyain.c_str());

  string sicil, no, tarih, baslangic_s, bitis_s;

  for(int i = 0;i<MAX;i++)//randevu dosyasýnýn satýrlarýný okuyor
  {
    
    if( dosya.eof() ) {randevu_sayisi=i-1; break;}
    dosya>>no>>sicil;
    for(int var = 0; var<AKADEMISYEN;var++)//sicil nosu ayný olan akadamisyen objesini arýyor
    {
      if(!sicil.compare(ak[var].getSicil()))//sicil stringi objenin siciline eþit ise
        x=var;
        
    }
    if(x==-1)
      cout<<"-----ERROR akademisyen bulunamadý\n";
    else
      randevu[i].setAkademisyen(ak[x]);
    
    for(int var = 0; var<OGRENCI;var++)//öðrenci nosu ayný olan öðrenci objesini arýyor
    {
      if(!no.compare(ogr[var].getNo()))
        x=var;
    }
    randevu[i].setOgrenci(ogr[x]);
    dosya>> tarih;
    randevu[i].setTarih(tarih);
    dosya>>baslangic_s;
    randevu[i].setBaslangic(baslangic_s);
    dosya>> bitis_s;
    randevu[i].setBitis(bitis_s);
  }
  dosya.close();
  for(int temp=0;temp<randevu_sayisi; temp++)
    date_and_time_to_int(randevu[temp]);
}

int Show_a(Akademisyen akademisyen []){//Akademisyenlerin sýra numaralarýný ve isimlerini ekranda gösteriyorum
  string sicil, ana_dal, unvan;
  int i;
  for( i=0;i<AKADEMISYEN;i++){
    if(akademisyen[i].ad=="")
      break;
    cout<<i<<". "<<akademisyen[i].ad<<" "<<akademisyen[i].soy<<'\n';
  }
  return i-1;
}

int say_r(Randevu randevu[])//Randevularý ekranda listeliyorum
{
  int i;
  for( i = 0;i<MAX;i++)
  {
    if(randevu[i].getOgrenci()=="")
      return i;
  }
  return i;
}

int Show_r(Randevu randevu[])//Randevularý ekranda listeliyorum
{
  int i;
  randevu_sayisi=say_r(randevu);
  
  for( i = 0;i<randevu_sayisi;i++)
  {
    if(randevu[i].getOgrenci()=="")
      return i;
    cout<<randevu[i].getOgrenci()<<"\t";
    cout<<randevu[i].getAkademisyen()<<"\t";
    cout<<randevu[i].getTarih()<<"\t";
    cout<<randevu[i].getBaslangic()<<"\t";
    cout<<randevu[i].getBitis()<<"\n";
  }
  return i;
}

bool check_time(string start, string end){
  if(atoi(start.substr(0,2).c_str())>atoi(end.substr(0,2).c_str()))return false;
  //dk kontrolü
  if(atoi(start.substr(3,2).c_str())>atoi(end.substr(3,2).c_str()))return false;
  return true;
}

bool check_time_string(string time){
  //saat uzunluðu 5ten farklýysa
  if(time.length()!=5)return false;
  //saat gunu kontrolü
  if(23<atoi(time.substr(0,2).c_str())||atoi(time.substr(0,2).c_str())<0)return false;
  //dk kontrolü
  if(59<atoi(time.substr(3,2).c_str())||atoi(time.substr(3,2).c_str())<0)return false;
  return true;
}

bool check_tarih_string(string tarih){
  //tarih uzunluðu 10dan farklýysa
  if(tarih.length()!=10)return false;
  //tarih gunu kontrolü
  if(31<atoi(tarih.substr(0,2).c_str())||atoi(tarih.substr(0,2).c_str())<1)return false;
  //ay kontrolü
  if(12<atoi(tarih.substr(3,2).c_str())||atoi(tarih.substr(3,2).c_str())<1)return false;
  //yýl kontrolü
  if(2019<atoi(tarih.substr(6,4).c_str())||atoi(tarih.substr(6,4).c_str())<2018)return false;
  return true;
}

//Çakýþma yokmuþ gibi kullanýlýyor.(yetiþmedi)
bool colision(Akademisyen ak[],Randevu r[],string tarih, string start, string end, int akademisyen_sirasi){
  
  int saat_s, dakika_s, saat_end, dakika_end;
  int gun,ay,yil;

  gun= atoi(tarih.substr(0,2).c_str());
  ay= atoi(tarih.substr(3,2).c_str());
  yil= atoi(tarih.substr(6,4).c_str());
  

  saat_s=(atoi(start.substr(0,2).c_str()));
  dakika_s=(atoi(start.substr(3,2).c_str()));

  saat_end=(atoi(end.substr(0,2).c_str()));
  dakika_end=(atoi(end.substr(3,2).c_str()));
  //hatalý
  date_and_time_to_int(r[randevu_sayisi-1]);

  for(int i=0; i<randevu_sayisi; i++){
    cout<<"KONTROL"<<endl;
    //oluþmuþ randevular arasýnda bir çakýþma varsa
    if(r[i].getSaatStart()>r[i].getSaatEnd())
      return true;
    else if(r[i].getDakikaStart()<r[i].getDakikaEnd()&&r[i].getSaatStart()<=r[i].getSaatEnd())
      return true;
    //oluþmuþ randevularýn çakýþma kontolü bitti
    //verilen tarih ve saat çakýþma kontrolü baþladý
    cout<<r[i].getYil()<<"if=="<<yil<<endl;
    
    if(r[i].getYil()==yil&&r[i].getGun()==gun&&r[i].getAy()==ay){
      
      cout<<"KONTROL 2"<<endl;
      

      //karþýlaþtýrmaya baþladý tarihi bulduk
      if(r[i].getAkademisyen()==ak[akademisyen_sirasi].getSicil())
      {cout<<"KONTROL 3"<<endl;
        //akademisyen eþleþti. o hoca o saatte boþ mu bakacaðýz
        if(saat_s<=r[i].getSaatStart()&&saat_end>=r[i].getSaatEnd()){
          //randevu olan saatler arasýndayýz
          //dakikalarý kontrol edelim
          if(dakika_s<=r[i].getDakikaStart()&&dakika_end>=r[i].getDakikaEnd())
            return true;
        }
      }
    }
  }
  return false;
}
void menu(){
  cout<<"Randevu almak istiyorum ----> 1"<<endl;
  cout<<"Randevumu silmek istiyorum ----> 2"<<endl;
  cout<<"Randevulari listele ----> 3"<<endl;
  cout<<"Randevuyu guncelle ----> 4"<<endl;
}

void randevulari_kaydet(Randevu r[]){
  if( remove( "randevu.txt" ) != 0 )
    perror( "Error deleting file" );
  
  Show_r(r);
  randevu_sayisi=say_r(r);
  //date_and_time_to_int(r[randevu_sayisi]);
  ofstream dosya;
  dosya.open("randevu.txt");
  
  for(int i=0; i<randevu_sayisi; i++){
    dosya<<r[i].getOgrenci()<<" ";
    dosya<<r[i].getAkademisyen()<<" ";
    dosya<<r[i].getTarih()<<" ";
    dosya<<r[i].getBaslangic()<<" ";
    dosya<<r[i].getBitis()<<endl;
  }
  dosya.close();
}

bool randevuyu_sil(Randevu r[], Ogrenci o[],
  string no){
  int  x=-1;

  for(int var = 0; var<OGRENCI;var++)//öðrenci nosu ayný olan öðrenci objesini arýyor
  {
    if(!no.compare(r[var].getOgrenci()))
    {
      x=var;
      break;
    }
  }
  if(x==-1){
    //bulamadým ogrenciyi
    cout<<"seni bulamadik!\n";
    //menu();
    return 0;
  }
  else
    cout<<x<<endl;
  int var;
  for( var=x; var<randevu_sayisi; var++)
  {
    r[var].setOgrenci(r[var + 1].getOgrObj());
  }
  r[var].resetOgrenci();
  randevulari_kaydet(r);
  return 1;
}

void konsol(Randevu r[],Akademisyen a[], Ogrenci o[]){
  
  string no, sicil, tarih, baslangic_s, bitis_s;
  
  int cevap, i, randevu_sayisi=0;
  menu();
  cout<<"Ne yapmak istiyorsunuz? (1,2,3,4)\n"<<endl;
  cin>>cevap;

  if(cevap == 3){
    randevu_sayisi=Show_r(r);
  }
  
  if(cevap==1){
    int ak_sayi=0;
    cout<<"Akademisyen isimleri ve sira numaralari: "<<endl;
    
    ak_sayi=Show_a(a);

    cout<<"Randevu alacaginiz akademisyenin sira numarasini giriniz\n"<<endl;
    cin>>i;
    if (i<0||i>ak_sayi){
      cout<<"hatali giris"<<endl;
      return;
    }
    cout<<"Randevu icin ogrenci numaranizi giriniz\n";
    cin>>no;
    cout<<"Randevu almak istediginiz tarihi gun, ay ve yil olarak yaziniz(Orn.12.12.2018)\n"<<endl;
    cin>>tarih;
    if(!check_tarih_string(tarih))
    {
      cout<<"hatali giris"<<endl;
      return;
    }
    cout<<"Randevunuzun baslangic ve bitis saati: \n"<<endl;
    cin>>baslangic_s;
    cin>>bitis_s;
    if(!check_time_string(baslangic_s)||!check_time_string(bitis_s))
    {
      cout<<"hatali giris"<<endl;
      return;
    }

    if(!check_time(baslangic_s,bitis_s))
    {
      cout<<"hatali saat"<<endl;
      return;
    }


    if(colision(a,r,tarih,baslangic_s, bitis_s,i))
      {
        cout<<"cakisma var"<<endl;
        return;
      }
    cout<<"Randevunuzu guncellemek(kaydetmek) icin --> 4: "<<endl;
    cin>>cevap;
    int x=-1;//error durumu
    if(cevap == 4){
      
      randevu_sayisi=say_r(r);

      r[randevu_sayisi].setAkademisyen(a[i]);
      
      for(int var = 0; var<OGRENCI;var++)//öðrenci nosu ayný olan öðrenci objesini arýyor
      {
        if(!no.compare(o[var].getNo()))
          x=var;
      }
      if(x==-1){
        //bulamadým ogrenciyi
        cout<<"seni bulamadik!\n";
        //menu();
        return;
      }
      r[randevu_sayisi].setOgrenci(o[x]);
      r[randevu_sayisi].setTarih(tarih);
      r[randevu_sayisi].setBaslangic(baslangic_s);
      r[randevu_sayisi].setBitis(bitis_s);      
      randevulari_kaydet(r);
    }
  }

  if(cevap == 2){
  cout<<"Ogrenci numaranizi giriniz\n"<<endl;
  cin>>no;
  
  
  if (randevuyu_sil(r,o,no))
    cout<<"Randevunuz iptal edildi"<<endl;
  else 
    cout<<"silinemedi "<<endl;
  }

  if(cevap<1||cevap>4)
    cout<<"yanlis giris\n";
    
} 

int main() {
  Akademisyen a[AKADEMISYEN];
  Ogrenci o[OGRENCI];
  Randevu r[MAX];

  read_o(o);
  read_a(a);  
  read_r(r,a,o);

  Show_r(r);

  while(true)
    konsol(r, a, o); 

  return 0;
}
  
