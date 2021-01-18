import processing.serial.*;
import ddf.minim.*;

int matriz[][][] =
{
  //lvl1
  {
{1,0,1,0,0,0,1,1,1,1},
{1,0,0,0,1,0,0,0,0,1},
{0,0,1,1,1,1,1,1,0,0},
{1,0,1,0,1,0,1,1,1,0},
{1,0,0,0,0,0,0,0,1,0},
{1,1,1,1,0,0,1,1,0,0},
  },
 //lvl2
 {
{1,1,1,0,0,0,1,1,0,0},
{0,0,0,0,1,0,0,0,0,0},
{0,1,1,0,0,2,1,0,2,1},
{0,1,0,1,1,0,1,0,0,1},
{0,0,0,0,1,1,0,2,0,1},
{1,1,1,0,0,0,0,1,0,0},
 },
//lvl 3
{
{1,0,1,0,0,0,0,1,1,1},
{1,0,0,0,1,2,0,0,0,0},
{0,0,1,0,1,0,1,2,2,0},
{1,0,2,1,0,0,1,2,0,0},
{0,0,0,2,1,0,2,1,0,2},
{1,2,0,0,0,0,0,1,0,0},
},
//lvl4
{
{1,0,1,0,0,0,1,1,0,0},
{1,0,0,0,1,0,0,0,0,0},
{0,0,1,0,1,0,1,1,0,1},
{1,0,1,0,0,0,1,1,1,1},
{0,0,0,0,0,0,0,0,0,1},
{0,0,1,1,0,0,1,1,0,0},
},
};
Serial port;
PFont fuente;

//Corbel-Bold-48.vlw
int levels=0;
int x,y;
int y1=2;
int x1=0;
int y2=2;
int x2=0;
int fil=0;
int col=0;
PImage img; 
PImage fondo;
PImage bandera;
PImage enemigo;

int px,py;
int estado=0;
String dato;
int posx;
int posy;
float enemigox=700.0;
float enemigoy=200.0;
float vel=3.0;

int fil1=0,col1=0;
 
 void setup(){
 size(1000,600);
 port= new Serial(this, "COM10",9600);
 fuente=loadFont("Corbel-Bold-48.vlw");
 textFont(fuente);
 
 
 }
 void draw(){

 switch(estado){
 
 case 0:
 //fondo=loadImage("fondo.png");
 //imageMode(CENTER);
 //image(fondo,1000,600);
 background(#7CF5EC);
 textSize(55);
 fill(0);
 text("SISTEMAS EMBEBIDOS",250,100);
 text("MI VIDEOJUEGO",325,150);
 textSize(30);
 text("PRESIONA ESPACIO",400,225);
 text("PARA INICIAR ",450,275);
 fill(#848E8D);
 stroke(#4A4950);
 strokeWeight(10);
 ellipse(525,443,300,300);
 //BOTON C
 fill(0,0,250);
 strokeWeight(5);
 stroke(#190B71);
 ellipse(525,375,75,75);
 fill(255);
 textSize(40);
 text("C",515,385);
 //
 //BOTON D
 fill(#FFE200);
 stroke(#BFAA08);
 strokeWeight(5);
 ellipse(525,500,75,75);
 fill(255);
 text("D",515,510);
 
 //
 
 //BOTON A
 fill(0,250,0);
 stroke(#126F0A);
 strokeWeight(5);
 ellipse(435,440,75,75);
 fill(255);
 text("A",423,450);
 
 //BOTON B
 fill(250,0,0);
 stroke(#831725);
 strokeWeight(5);
 ellipse(610,440,75,75);
 fill(255);
 text("B",600,450);
 
 
 
 estado++;
 
 break;
 
 case 1:
 if(key==' '){
 img=loadImage("Bloque_oro.png");
 fondo=loadImage("fondo_espacio.png");
 bandera=loadImage("bandera.png");
 enemigo=loadImage("ghost.png");
 background(fondo);
 
 //image(bandera,900,500,100,100);
 fill(255);
 //fill(0);
 //rect(0,0,900,600);
for(;fil<6;fil++){
    y=fil*100;
    for(col=0;col<10;col++){
      x=col*100;
      if(matriz[levels][fil][col]==1){
       imageMode(CENTER);
       image(img,x+50,y+50,100,100); // ubicar la imagen en la interfaz
      }
    }
  }
 image(bandera,950,550,100,100);
 estado++;

 }
 break;
 case 2:
 if(levels==3){
 background(fondo);
 fill(255);
 textSize(40);
 text("FELICIDADES GANASTE",300,275);
 text("PRESIONA X PARA VOLVER A JUGAR",200,325);
 
 if(key=='x'){
   
 estado=0;
 levels=0;
 //
 x2=0;
 y2=2;
 fil=0;
 col=0;
 x1=0;
 y1=2;
 col1=0;
 fil1=0;
 }
 }
 break;
 }

 move();//LLAMO A LA FUNCION QUE LE DA MOVIMIENTO AL OBJETO
 
 
 
 if(estado==2 && levels==3){
 fill(0);
 stroke(0);
 ellipse(50,250,56,56);
 
 
 }
 
 }  

 void move(){ 
   
 posx=50+(x2*100);
 posy=50+(y2*100);
  fill(#7CF5EC);
  stroke(#7CF5EC);
  //int posx=50+(x2*100);
  //int posy=50+(y2*100)
  //if(posx==900 && posy==600)
  ellipse(posx,posy,50,50);
 
  
 //  fill(#7CF5EC);
 //ellipse(50,250,50,50);
   
  while (port.available() > 0) {
  
  dato=port.readString();
 //A-> IZQ
 //B->DER
 //C-> UP
 //D-> DOWN
  
  
  fill(0);
  stroke(0);
  ellipse(posx,posy,56,56);
 switch(dato){
   case "A":
    if(x1>0){
       x1--;
       if(matriz[levels][y1][x1]!=1){
        x2--;
       }
       else
       x1=x2;
    }
    //println(str(x2)+str(y2));
   println(str(posx)+" "+str(posy));
   break;
   case "B":
        if(x1<9){
         x1++;
         if(matriz[levels][y1][x1]!=1){
          x2++;
        }
        else
        x1=x2;
    }
      //println(str(x2)+str(y2));
   println(str(posx)+" "+str(posy));
   break;
      case "C":
        if(y1>0){
         y1--;
         if(matriz[levels][y1][x1]!=1){
          y2--;
        }
        else
        y1=y2; 
    }
     // println(str(x2)+str(y2));
      println(str(posx)+" "+str(posy));
   break;
       case "D":
        if(y1<5){
         y1++;
         if(matriz[levels][y1][x1]!=1){
          y2++;
        }
        else
        y1=y2;
    }
      println(str(posx)+" "+str(posy));
   break;
 }

if(matriz[levels][y1][x1]==2){
y1=2;
x2=0;
y2=2;
x1=0;
//levels=0;
}

 impresionNiveles();
 }
 //println(dato);
  }
  
  
  void impresionNiveles(){
   if(posx==850 && posy==550 || posx==950 && posy==450){
    // enemigox=650;
     //enemigoy=150;
     levels++; 
     println(str(levels));
     background(fondo);
     
     fill(255);
       x2=0;
       y2=2;
       fil=0;
       col=0;
       x1=0;
       y1=2;
       fil1=0;
       col1=0;
//rect(enemigox,enemigoy,100,100);
//enemigox=enemigox+vel;
//if(enemigox>700+vel){
//enemigox=-vel;
//}
    for(;fil<6;fil++){
    y=fil*100;
     for(col=0;col<10;col++){
      x=col*100;
      if(matriz[levels][fil][col]==1){
       imageMode(CENTER);
       image(img,x+50,y+50,100,100); // ubicar la imagen en la interfaz
        
      }
    }
  }
  //imagen del enemigo
   for(;fil1<6;fil1++){
    y=fil1*100;
     for(col1=0;col1<10;col1++){
      x=col1*100;
      if(matriz[levels][fil1][col1]==2){
       imageMode(CENTER);
       image(enemigo,x+50,y+50,100,100); // ubicar la imagen en la interfaz
        
      }
    }
  
  
  }
  image(bandera,950,550,100,100);
 
  //image(enemigo,enemigox,enemigoy,50,50);
  //fill(255);
  //rect(enemigox,enemigoy,100,100);
  //enemigox=enemigox+vel;
  
 
    
  
  }
  }
 
