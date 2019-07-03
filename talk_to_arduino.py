#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32
from random import randint

def genera_numero_random():
    rnd= randint(0,2500)
    return rnd

if __name__=='__main__':
    rospy.init_node('talk_to_arduino')
    pub=rospy.Publisher('/topico/arduino', Int32, queue_size=10)
    rate= rospy.Rate(10)

    while not rospy.is_shutdown():
        randon=generate_random_number()
        pub.publish(randon)

rate.sleep()
