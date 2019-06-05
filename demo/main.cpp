#include "Controller.h"
#include "Main_view.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Controller mainctrl;
    mainctrl.show_initialview("./data.txt");

    return app.exec();   //进入事件循环
}
