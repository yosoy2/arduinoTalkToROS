
#include <ros.h>                             
#include <std_msgs/Int32.h>

/*importamos la libreria de ROS  de la carpeta mensajes standares 
importamos el mensaje Int32 que es un entero de 32 bits*/
  
ros::NodeHandle nh;
                         
/*para no estar escribiendo NodeHandle todo el tiempo le ponemos nh
es como el import as de python*/

float variable;

//definimos una variable que sera la leida por el arduino                            

void recibidor(const std_msgs::Int32 &msg){

/* esta funcion recibidor toma la variable llamada
variable y la compara y segun eso enciende el led
del arduino, msg.data es el dato que inventamos
en la funcion y lo compare con variable .data es
como esta definido el mensaje Int32*/
                                              
  variable=msg.data;
  if(variable < 2200 )
  digitalWrite(LED_BUILTIN,0);
  else
  digitalWrite(LED_BUILTIN,1);  
  }     
  
/* notar que aun no le hemos dicho a donde se suscribe
en el caso que deban mover el servo, deben escribir 
la funcion aquie inventarse sus variables*/
                        

ros::Subscriber<std_msgs::Int32> sub("/topico/arduino", &recibidor);

/* aqui es donde nos suscibimos al topico "/topico/arduino"
y tambien que funcion lo toma, en este caso es la recibidor*/

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  nh.initNode();
  nh.subscribe(sub);

 /* definimos el led como salida, es importante hacerlo
 pero e iniciamos el nodo y una subcripcion llamada sub
 que es nombre que tiene arriba sub("topico, &funcion....)"*/
}

void loop() {
  // put your main code here, to run repeatedly:

  nh.spinOnce();
  delay(1);

}
