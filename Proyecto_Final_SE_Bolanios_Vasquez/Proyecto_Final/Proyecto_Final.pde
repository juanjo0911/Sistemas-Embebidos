import processing.serial.*;
PImage conta,puro; 
Serial port;
int porknn,porbay,clas,aux=0,aux2=0,aux3=0,aux4=0,a=0,b=0;
String dato1,dato,dato2;
int i=0,j=0;
String vec[]={"","",""};
String mat[][]={
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},
{"",""},

};
int k=0;
void setup(){
  size(1000,600);
port=new Serial(this,"COM5",9600);

background(#39CAD1);

conta=loadImage("contaminado.jpg");
puro=loadImage("puro.jpg");
textSize(35);
text("Proyecto Final",380,50);
 textSize(30);
 text("Bolaños Bolivar y Vasquez Juan Jose",210,100);
stroke(0);
strokeWeight(5);
}



void draw(){

conexion();

}

void conexion(){

if(port.available()>0){ 
 background(#39CAD1);
 textSize(35);
 text("Proyecto Final",380,50);
 textSize(30);
 text("Bolaños Bolivar y Vasquez Juan Jose",210,100);
  dato=port.readString();
    println(dato);
String[] parts = dato.split("-");
String part1 = parts[0];
println(part1);
textSize(20);
 text("Porcentaje Clasificador KNN: "+part1+"%",300,220+28);
String part2 = parts[1];
println(part2);
 text("Porcentaje Clasificador bayesiano: "+part2+"%",300,220+56);
String part3 = parts[2];
println(part3);
 switch(part3){
 case "1":
 text("La Etiqueta pertenece a aire no contaminado ",300,220+84);
 imageMode(CENTER);
  image(puro,500,450,200,200);
 break;
 case "2":
 text("La Etiqueta pertenece a aire contaminado ",300,220+84);
 imageMode(CENTER);
 image(conta,500,450,200,200);
 break;
 
 }
    
  
 
  
}
}
