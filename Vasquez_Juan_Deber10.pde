float x;
float y;
float horizontal;
float vertical;
void setup(){
size(700,700);
background(#48D8D7);
x=width/2;
y=height/2;
vertical=-20;
horizontal=-20;
}

void draw(){
strokeWeight(5);
stroke(0,random(100,250),random(100,250));
fill(random(100,250),random(100,250),random(100,250));
ellipse(x,y,100,100);
}


void keyPressed(){
  
  switch(keyCode){
    case UP:
    
    y=y+vertical;
    background(#48D8D7);
    
    break;
    
    case DOWN:
    y=y-vertical;
    background(#48D8D7);
    break;
    
    case LEFT:
    x=x+horizontal;
    background(#48D8D7);
    break;
    
    case RIGHT:
    x=x-horizontal;
    background(#48D8D7);
    break;
  }
}
