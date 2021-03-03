//include libs 
#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>

//main func
int main()
{
    /* code */
    int rc;
    struct mosquitto *mosq;

    //must be called before any other mosquitto functions 
    mosquitto_lib_init();

    //create a new mosquitto client instance
    mosq=mosquitto_new("publisher-test",true,NULL);

    //connect to MQTT broker
    rc = mosquitto_connect(mosq, "localhost",1883,60);

    //if the result is not equal to zero then we have an error with our connection...
    if(rc!=0){
        printf("Clinet do not connect to borker! Error code: %d\n", rc);
        
        //free the memory associated with a mosquitto client instance
        mosquitto_destroy(mosq);
        return -1;
    }

    printf("We are now connected to the borker!\n");

    //publish a message to a given topic
    mosquitto_publish(mosq,NULL,"test/t1", 6,"Hello", 0 ,false);

    //disconnect from the broker
    mosquitto_disconnect(mosq);

    //free the memory associated with a mosquitto client instance
    mosquitto_destroy(mosq);

    //free resources associated with the library
    mosquitto_lib_cleanup();


    return 0;
}
