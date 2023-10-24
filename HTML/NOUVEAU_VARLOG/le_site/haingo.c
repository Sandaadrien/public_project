
#include "haingo.h"

void fonction_css(){
	printf("<style>");
	printf(".conteneur1-image{"
			"border-radius: 50%%;"
			"position: absolute;width: 40%%;right: 10%%;top: 10%%;height: 90%%;"
 			"overflow: hidden;"
			"}"

	);
	printf(".conteneur2-image{"
			"display:flex;"
			"animation: conteneur2-image 25s infinite ease-in-out;"
			"}"
	);
	printf(".logo{width: 80%%;margin: 10%%;}");
	printf("@keyframes conteneur2-image{"
			"0%%, 20%%{transform: translateX(0);}"
			"25%%, 45%%{transform: translateX(-100%%);}"
			"50%%, 70%%{transform: translateX(-200%%);}"
			"75%%, 95%%{transform: translateX(-300%%);}"
			"100%%{transform: translateX(-400%%);}"
			"}"
	);
	printf(".navbar{"
				"background-color: transparent;"
				"display: flex; flex-direction: column;justify-content: space-between; align-items: center;"
				"height: 10%%;"
			"}"
	);
	
	printf(".debut{"
			"width: 500px;height: 100%%;"
			"display: flex; justify-content: center;align-items: center;"
			"}"
	);
	printf(".debut>ul{height: 100%%;}");
	printf(".debut>ul>li{margin-right: 60px; height: 100%%;font-size: 20px;position: relative}");
	printf("a{display: flex;align-items: center;text-decoration: none; color: black;height: 100%%;}");
	
	printf(".debut>ul>li a:after{"
			"position: absolute;left:0;bottom: -1px;"
			"content: \"\";"
			"width: 0; background-color: black; height:4px;"
			"transition: 0.5s ease-in-out;"
			"}"
	);
	printf(".debut>ul>li a:hover:after{"
			"width: 100%%;"
			"}"
	);
	
	printf(".lien{"
			"list-style-type: none;"
			"display: flex;"
			"justify-content:space-between;"
			"width: 80%%;"
			"text-align: center;"
			"margin: auto 10%%;"
			"}"
	);


	printf(".ul-interne{"
			"display: flex;"
			"list-style-type: none;"
			"justify-content: space-around;"
			"}"
	);

	printf(".farany{padding-top: 15px;}");
	printf("input[type=\"submit\"]{width: 200px;height: 40px;font-size: 16px;}");
	printf("input[type=\"text\"]{"
			"height: 40px;"
			"width: 400px;"
			"padding: 10px 30px;"
			"font-size: 15px;"
			"font-weight: 600;"
			"}"
	);

	printf("hr{width: 90%%;}");

	printf(".deconnection{"
			"width: 40px;"
			"}"
	);
	printf(".div-connection{position: absolute; width: 400px; height : 100px;bottom: 2%%;left: 2%%;}");
	printf(".div-connection::after{"
			"position: absolute;"
			"content: \"\";"
			"background-color: red;"
			"transform: rotate(44deg);"
			"bottom:80px;left: 3.5%%;width: 50px; height: 50px; "
			"z-index: 4;"
			"display: none;"
			"}"
	);
	
	printf(".div-connection::before{"
			"position: absolute;"
			"content: \"\";"
			"background-color: red;"
			"transform: rotate(44deg);"
			"bottom:80px;left: 3.5%%;width: 50px; height: 50px; "
			"display: none;"
			"z-index: 4;"
			"}"
	);

	printf(".connection{"
			"width: 70px;height:70px;"
			"background-color: yellow;"
			"bottom: 3%%;"
			"left: 3%%;"
			"border-radius: 50%%;"
			"position: absolute;"
			"box-shadow: 0 0 10px black;"
			"}"
	);
	printf(".div-log{"
			"position: absolute;"
			"width: 300px;height: 100px;"
			"font-size: 20px;"
			"text-align: center;"
			"padding: 30px 10px;"
			"background-color: red;"
			"border-radius: 10px;"
			"bottom:100px;left: -10px;"
			"box-shadow: 0 0 5px black;"
			"display: none;"
			"}"
	);
	
	printf("div.div-connection:hover .div-log{"
			"cursor: pointer;"
			"display: flex;"
			"}"
	);
	printf("div.div-connection:hover::after ,div.div-connection:hover::before {display: flex;}");


	printf(".deconnection{margin: 20px 10px 0 10px;}");


	printf("</style>");
}
