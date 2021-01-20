import processing.serial.*;
Serial port;
PImage grid;
float dato;
int i=0;
float altura,peso;
void setup(){
size(1000,800);
port=new Serial(this,"COM10",9600);
grid=loadImage("grid_fondo.png");
background(0);
textSize(35);
text("REGRESION LINEAL",300,100);

stroke(0);
strokeWeight(5);
//line(42,0,42,800);
//line(0,755,1000,755);
}





void draw(){
conexion();
graficar();
grid();

}


void conexion(){
 if(port.available()>0){ 
 while(i==0){
  dato=port.read();
  altura=int(dato); //Convertir de string a int
  
  print("Dato1");
  print(dato);
  i++;
 }
  while(i==1){
  peso=port.read();
  print("Dato2");
  print(peso);
  i=0;
  }


 }
}

void graficar(){
stroke(0,250,0);
fill(0,250,0);
ellipse(100+(170-155)*(600/30),750-(67-0)*450/90,5,5);
ellipse(100+(180-155)*(600/30),750-(80-0)*450/90,5,5);
ellipse(100+(170-155)*(600/30),750-(65-0)*450/90,5,5);
ellipse(100+(178-155)*(600/30),750-(75-0)*450/90,5,5);
ellipse(100+(160-155)*(600/30),750-(55-0)*450/90,5,5);
ellipse(100+(163-155)*(600/30),750-(60-0)*450/90,5,5);
ellipse(100+(165-155)*(600/30),750-(63-0)*450/90,5,5);
ellipse(100+(170-155)*(600/30),750-(70-0)*450/90,5,5);
ellipse(100+(164-155)*(600/30),750-(62-0)*450/90,5,5);
ellipse(100+(176-155)*(600/30),750-(77-0)*450/90,5,5);
ellipse(100+(164-155)*(600/30),750-(60-0)*450/90,5,5);
ellipse(100+(170-155)*(600/30),750-(76-0)*450/90,5,5);
ellipse(100+(170-155)*(600/30),750-(56-0)*450/90,5,5);
ellipse(100+(168-155)*(600/30),750-(60-0)*450/90,5,5);
//grafico los datos que se obtienen de la comunicacion serial
stroke(0,250,0);
//strokeWeight(5);
fill(#D67213);
ellipse(100+(altura-155)*(600/30),750-(peso-0)*450/90,5,5);

}
void grid(){
noFill();
stroke(0,0,250);
//ejes

//vertical
stroke(0,0,250);
line(100,300,100,750);
//horizontal
line(100,750,700,750);
strokeWeight(0);
stroke(250,0,0);
//vertical
//line(100,300,100,750);//incrementa de 100 
line(200,300,200,750);
line(300,300,300,750);
line(400,300,400,750);
line(500,300,500,750);
line(600,300,600,750);
line(700,300,700,750);
//horizontal
line(100,300,700,300);//incrementa de 50
line(100,350,700,350);
line(100,400,700,400);
line(100,450,700,450);
line(100,500,700,500);
line(100,550,700,550);
line(100,600,700,600);
line(100,650,700,650);
line(100,700,700,700);
//line(100,750,700,750);

//trazo de la linea
stroke(255);
line(200,475,600,350);
 
//etiquetas para el plano
//peso
fill(0,250,0);
stroke(0,250,0);
textSize(20);
text("PESO",75,275);
text("90",70,305);
text("80",70,355);
text("70",70,405);
text("60",70,455);
text("50",70,505);
text("40",70,555);
text("30",70,605);
text("20",70,655);
text("10",70,705);
text("0",70,755);

 //altura
text("ALTURA",700,750);
text("155",80,775);
text("160",180,775);
text("165",280,775);
text("170",380,775);
text("175",480,775);
text("180",580,775);
text("185",680,775);
 
 
}
