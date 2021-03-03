//include libs
#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>

//on_connect callback function
void on_connect(struct mosquitto *mosq,void *obj, int rc){
    printf("ID: %d\n", *(int * ) obj);
    if(rc){
        printf("Error with result code: %d\n",rc);
        exit(-1);
    }
    mosquitto_subscribe(mosq,NULL, "test/t1", 0);
}

//on_message callback function
void on_message(struct mosquitto *mosq,void *obj, const struct mosquitto_message *msg){
    printf("New message with topic: %s: %s\n", msg->topic, (char * ) msg->payload);
}

//main func
int main()
{
    //code
    int rc, id =12;

    //must be called before any other mosquitto functions
    mosquitto_lib_init();
    struct mosquitto *mosq;

    //create a new mosquitto client instance
    mosq = mosquitto_new("subcriber-test", true, &id);

    //set the connect callback. 
    //This is called when the broker sends a CONNACK message 
    //in response to a connection.
    mosquitto_connect_callback_set(mosq, on_connect);

    //Set the message callback. 
    //This is called when a message is received
    //from the broker.
    mosquitto_message_callback_set(mosq, on_message);

    //connect to an MQTT broker
    rc = mosquitto_connect(mosq,"localhost",1883,10);
    if(rc){
        printf("Could not connect to Broker with reurn code %d\n",rc);
        return -1;
    }

    //This is part of the threaded client interface.
    //Call this once to start a new thread to process network traffic.
    //This provides an alternative to repeatedly calling yourself.
    mosquitto_loop_start(mosq);
    printf("Press Enter to quit...\n");
    getchar();

    mosquitto_loop_stop(mosq,NULL);

    //use to free memory associated with a mosquitto client instance.
    mosquitto_destroy(mosq);

    //call to free resources associated with the library.
    mosquitto_lib_cleanup();

    return 0;
}
