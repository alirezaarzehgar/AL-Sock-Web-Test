#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

char sendBuff [ ] =
{
                        "<!DOCTYPE html>\n"
                        "<html>\n"
                        "<head>\n"
                        "  <meta charset=\"utf-8\">\n"
                        "  <title>Hacked By iRanians</title>\n"
                        "  <style type=\"text/css\">\n"
                        "      body\n"
                        "      {\n"
                        "        background-color: black;\n"
                        "        background-image: /*url(https://i.pinimg.com/originals/dd/e5/f5/dde5f562b86e9f9e3022c6cf6fdb7cd8.jpg)*/ url(35402.jpg);\n"
                        "        background-repeat: no-repeat;\n"
                        "        background-position: center center;\n"
                        "        background-size: 1000px;\n"
                        "      }\n"
                        "\n"
                        "  </style>\n"
                        "</head>\n"
                        "<body>\n"
                        "    <audio hidden=\"true\" autoplay=\"true\" loop=\"true\">\n"
                        "    </audio>\n"
                        "    <div style=\"text-align: center; color: #00FB13;\n"
                        "      font-family: hacked; font-size: 80px;\n"
                        "      margin-top: 20px;\">Hacked <span style=\"color: #f6f078;\">By</span> iRanians</div>\n"
                        "  <center>\n"
                        "    <div style=\"color: #4a69bb; font-family: Impact; text-align: center; border: 2px solid white; width: 500px; height: 200px; font-size: 40px; margin-top: 20px;\">Your Security is Low <br/>And<br/> We Passed it!! <br/> <span style=\"color: #ffba5a;\"> IRaninan Hackers </span> <br/> <span style=\"font-family: Lucida Fax; font-size: 20px; color: gray;\">Sorry Admin :) </span></div>\n"
                        "  </center>\n"
                        "  <br/><br/>\n"
                        "  <h2 style=\"color: #730068; text-align: center;\">We Are:</h2> <br/>\n"
                        "    <marquee direction=\"right\" style=\"background-color: #2a1a5e;\">\n"
                        "      <div style=\"color: #f45905; font-family: Rockwell;\n"
                        "       font-size: 30px;\">"
                        "          ==========>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Ashkan_Z9&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-----------&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Farzan_Gh&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-----------&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Mrb3hz4d&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<==========\n"
                        "       </div>\n"
                        "    </marquee>\n"
                        "</body>\n"
                        "</html>\n"
};


int main(int argc, char *argv[])
{
    	int listenfd = 0, connfd = 0;
    	struct sockaddr_in serv_addr;

    	time_t ticks;
    	uint32_t ip = 0;
    	listenfd = socket(AF_INET, SOCK_STREAM, 0);
    	memset(&serv_addr, '0', sizeof(serv_addr));
    	inet_aton("192.168.1.10", (struct in_addr*)&ip);
    	serv_addr.sin_family = AF_INET;
    	serv_addr.sin_addr.s_addr = INADDR_ANY;
    	serv_addr.sin_port = htons(8080);

   	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    	listen(listenfd, 10);

    	while(1)
    	{
        	connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
    		fprintf(stderr, "New connection \n");
        	ticks = time(NULL);
        	write(connfd, sendBuff, strlen(sendBuff));

        	close(connfd);
        	sleep(1);
     	}
}
