//
// Created by BanMing on 4/29/2020.
//
class WebBrowser {
public:
    void clearCache();

    void clearHistory();

    void removeCookies();

    void clearEverything();
};

//封装性更好
void clearBrowser(WebBrowser &wb) {
    wb.clearCache();
    wb.clearEverything();
    wb.removeCookies();
}
