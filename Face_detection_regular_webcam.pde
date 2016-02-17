import processing.serial.*;
import java.awt.Rectangle;
import SimpleOpenNI.*;
import hypermedia.video.*;

//SimpleOpenNI cam;
OpenCV opencv;
float distanceN = 0; //the true value given by the equation
float distanceR = 0; //a rounded version of the distance, because having 3 decimal places in a dodgy equation is stupid
boolean xtrue = false; //variable used to see whether the x co-ordinates of the face are inside the middle quadrant
boolean ytrue = false; //same as above but y co-ordinates instead
int mid=10;

void setup() {
 // cam = new SimpleOpenNI(this); //initialize kinect camera
 // cam.setMirror(true);
 // cam.enableRGB(); //using the RGB camera.  Can not use IR camera now.
  
   size( 320, 240 );
    opencv = new OpenCV(this);
    //opencv.allocate(cam.rgbWidth(), cam.rgbHeight()); //size of image buffer
    opencv.capture( width, height );  
    opencv.cascade( OpenCV.CASCADE_FRONTALFACE_ALT );   // change this to where your frontal face xml is located
 
   // size(cam.rgbWidth(), cam.rgbHeight()); //size of window
}

void draw() {
    
    opencv.read();
  // cam.update();
  // opencv.copy(cam.rgbImage());
   //pushMatrix();
   //scale(-1,1);
  // beginShape();
   //text
   image( opencv.image(), 0, 0 );
   // popMatrix();
    // detect anything ressembling a FRONTALFACE
    Rectangle[] faces = opencv.detect();
    // draw detected face area(s)
   
    stroke(255,0,0);
    //if a face is on the screen
    for( int i=0; i<faces.length; i++ ) {
    noFill();  
    //rectMode(RADIUS);
    rect( faces[i].x, faces[i].y, faces[i].width, faces[i].height ); 
      stroke(0,0,255);
    rect(width/2-10,height/2-10,30,30);
    
    //middle quadrant Green
    if(faces[i].x+faces[i].width/2-10<width/2+10 && faces[i].x+faces[i].width/2-10>width/2-10 && faces[i].y+faces[i].height/2-10<height/2+10 && faces[i].y+faces[i].height/2-10>height/2-10)
    {   
      stroke(0,255,0);
     // rectMode(CENTER);
      rect( faces[i].x+faces[i].width/2-mid, faces[i].y+faces[i].height/2-mid, 20, 20 ); 
    }
    
    //top left quadrant Yellow
    else if(faces[i].y + faces[i].height/2< 120 && faces[i].x + faces[i].width/2<160)
    {
     stroke(150,150,0);
     rect( faces[i].x+faces[i].width/2-mid, faces[i].y+faces[i].height/2-mid, 20, 20 ); 
    }
    
   // bottom left quadrant purple
    else if(faces[i].y + faces[i].height/2> 120 && faces[i].x + faces[i].width/2<160)
    {
     stroke(150,0,150);
     rect( faces[i].x+faces[i].width/2-mid, faces[i].y+faces[i].height/2-mid, 20, 20 ); 
    }
    
    //bottom right quadrant white
    else if(faces[i].y + faces[i].height/2> 120 && faces[i].x + faces[i].width/2>160)
    {
     stroke(150,150,150);
     rect( faces[i].x+faces[i].width/2-mid, faces[i].y+faces[i].height/2-mid, 20, 20 ); 
    }
    
    //top right quadrant Red
   else 
    {
      stroke(255,0,0);
      rect( faces[i].x+faces[i].width/2-mid, faces[i].y+faces[i].height/2-mid, 20, 20 ); 
    }
    
    //below is what draws the values of x and y's on the face box
    
    textSize(18);
    fill(0, 102, 153);
    text(faces[i].x, faces[i].x, faces[i].y);
    text(faces[i].y, faces[i].x+50, faces[i].y);
    text(faces[i].width+faces[i].x, faces[i].x+faces[i].width-80, faces[i].y+faces[i].height+20);
    text(faces[i].height+faces[i].y, faces[i].x+faces[i].width-30, faces[i].y+faces[i].height+20);
    
    
    if(faces[i].x  < 107){
    //if the left border of the face is in the left quadrants    
    }
     
    if(faces[i].x + faces[i].width > 213){
    //if the right border of the face is in the right quadrants    
    }
  
    if(faces[i].y + faces[i].height > 160){
    //if the bottom border of the face is in the bottom quadrants    
    }

    if(faces[i].y < 80){
    //if the top border of the face is in the top quadrants 
    }

    //if the face's x values are inside the middle squre
    if ((faces[i].x > 107) && (faces[i].x + faces[i].width < 213)){
    xtrue = true;
    }
    else{
    xtrue = false; 
    }
  
    //if the face's y values are inside the middle square
    if((faces[i].y > 80) && (faces[i].y + faces[i].width < 160)){
    ytrue = true; 
    }
    else{
    ytrue = false; 
    }
 

     
 
    //if the face is in the middle square
    if(xtrue != false && ytrue != false){
    stroke(0,0,255); // blue colour
   
    rect(108, 81, 104, 78); //draw rectangle in the middle
    }

   distanceN = ((-0.4478*(faces[i].width))+117.31);
   distanceR = round(distanceN);
   fill(50);
   text(distanceR, 10, 30);
   text("cm", 80, 30);
   
  }
 
   
}
