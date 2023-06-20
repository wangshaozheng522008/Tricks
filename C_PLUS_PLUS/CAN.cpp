//*Using linux sockted-can*//
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <linux/can.h>
#include <linux/can/raw.h>

//* For can-fd*//
int canfd_on = 1;
int s, nbytes;
struct sockaddr_can addr;
struct ifreq ifr;
struct canfd_frame frame;
s = socket(PF_CAN, SOCK_RAW, CAN_RAW);//创建套接字
strcpy(ifr.ifr_name, "can2" );
ioctl(s, SIOCGIFINDEX, &ifr); 
addr.can_family = AF_CAN;
addr.can_ifindex = ifr.ifr_ifindex;
setsockopt(s, SOL_CAN_RAW, CAN_RAW_FD_FRAMES, &canfd_on, sizeof(canfd_on));//打开CAN_fd
bind(s, (struct sockaddr *)&addr, sizeof(addr));

//* For can*//
int s, nbytes;
struct sockaddr_can addr;
struct ifreq ifr;
struct can_frame frame;
s = socket(PF_CAN, SOCK_RAW, CAN_RAW);//创建套接字
strcpy(ifr.ifr_name, "can0" );
ioctl(s, SIOCGIFINDEX, &ifr); //指定 can0 设备
addr.can_family = AF_CAN;
addr.can_ifindex = ifr.ifr_ifindex;
bind(s, (struct sockaddr *)&addr, sizeof(addr));