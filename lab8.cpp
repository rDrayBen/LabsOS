#include <iostream>
#include <pthread.h>
#include <string>
#include <sys/resource.h>
#include <signal.h>
#include<sys/wait.h>

void *func(void * a) {
    int k;
    std::cout << "Kill: ";
    std::cin >> k;
    while (k != 1) {
        int ans;
        std::cout << "Open pages in browser?(1/0): ";
        std::cin >> ans;
        if(ans == 1){
            system("open https://www.google.com/search?q=wikipedia+english&client=firefox-b-lm&ei=50hZY6nFJNe0rgTV-4zgDA&oq=wikipedia+eng&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQARgAMgUIABCABDIFCAAQgAQyBQgAEIAEMgUIABCABDIFCAAQgAQyBQgAEIAEMgUIABCABDIFCAAQgAQyBQgAEIAEOgoIABBHENYEELADOgcIABCwAxBDSgQIQRgASgQIRhgAUMMFWN4MYJgcaAFwAXgAgAGEAYgBnAOSAQMzLjGYAQCgAQHIAQrAAQE&sclient=gws-wiz-serp");
            system("open https://duckduckgo.com/?t=ffab&q=wikipedia&ia=web");
            system("open https://www.bing.com/search?form=MOZLBR&pc=MOZI&q=wikipedia");
            system("open https://sg.search.yahoo.com/search;_ylt=Awrx_Z62SFljjswP_joi4gt.;_ylc=X1MDMjExNDcwODAwMgRfcgMyBGZyAwRmcjIDc2ItdG9wLXNlYXJjaARncHJpZANtN0owdGRZalJuLlFDWGxicklvdWtBBG5fcnNsdAMwBG5fc3VnZwMxMARvcmlnaW4Dc2cuc2VhcmNoLnlhaG9vLmNvbQRwb3MDMARwcXN0cgMEcHFzdHJsAzAEcXN0cmwDOQRxdWVyeQN3aWtpcGVkaWEEdF9zdG1wAzE2NjY3OTU2OTY-?p=wikipedia&fr=sfp&iscqry=&fr2=sb-top-search");  
        }
    }
}

int main() {

    // int pid = fork();

    // if (pid == -1) {
    //     return 1;
    // }

    // if (pid == 0) {
    //     while (1) {
    //         std::cout << "output\n";
    //         sleep(1);
    //     }

    // } else {
    //     kill(pid, SIGSTOP);
    //     int t, a;
    //     do {
    //         std::cout << "Suspend?: ";
    //         std::cin >> a >> t;

    //         if (a == 1) {
    //             if (t > 0) {
    //                 kill(pid, SIGCONT);
    //                 sleep(t);
    //                 kill(pid, SIGSTOP);
    //             }
    //         }

    //     } while (t > 0);

    //     kill(pid, SIGKILL);
    //     wait(NULL);
    // }



    pthread_t thread1;
    //pthread_create(&thread1, NULL, func, NULL);

    //int pid = fork();
    int k;
    std::cout << "Kill: ";
    std::cin >> k;
    if (k == 1) kill(getpid(), SIGKILL);

    std::cout << "Change priority: ";
    int a;
    std::cin >> a;
    if(a == 1){
        std::cout << "Choose priority(low, normal, high): ";
        std::string c;
        std::cin >> c;
        if(c == "low"){
            setpriority(PRIO_PROCESS, NULL, 6);
        }else if(c == "normal"){
            setpriority(PRIO_PROCESS, NULL, 0);
        }else if(c == "high"){
            setpriority(PRIO_PROCESS, NULL, -20);
        }else{
            std::cout << "Input is incorrect\n";
        }
    }

    std::cout << "Open pages: ";
    std::cin >> a;
    if(a == 1){
        system("open https://www.google.com/search?q=wikipedia+english&client=firefox-b-lm&ei=50hZY6nFJNe0rgTV-4zgDA&oq=wikipedia+eng&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQARgAMgUIABCABDIFCAAQgAQyBQgAEIAEMgUIABCABDIFCAAQgAQyBQgAEIAEMgUIABCABDIFCAAQgAQyBQgAEIAEOgoIABBHENYEELADOgcIABCwAxBDSgQIQRgASgQIRhgAUMMFWN4MYJgcaAFwAXgAgAGEAYgBnAOSAQMzLjGYAQCgAQHIAQrAAQE&sclient=gws-wiz-serp");
        system("open https://duckduckgo.com/?t=ffab&q=wikipedia&ia=web");
        system("open https://www.bing.com/search?form=MOZLBR&pc=MOZI&q=wikipedia");
        system("open https://sg.search.yahoo.com/search;_ylt=Awrx_Z62SFljjswP_joi4gt.;_ylc=X1MDMjExNDcwODAwMgRfcgMyBGZyAwRmcjIDc2ItdG9wLXNlYXJjaARncHJpZANtN0owdGRZalJuLlFDWGxicklvdWtBBG5fcnNsdAMwBG5fc3VnZwMxMARvcmlnaW4Dc2cuc2VhcmNoLnlhaG9vLmNvbQRwb3MDMARwcXN0cgMEcHFzdHJsAzAEcXN0cmwDOQRxdWVyeQN3aWtpcGVkaWEEdF9zdG1wAzE2NjY3OTU2OTY-?p=wikipedia&fr=sfp&iscqry=&fr2=sb-top-search");  
    }

    // kill(thread1, SIGINT);
    // kill(thread1, SIGCONT);
    //pthread_join( thread1, NULL);

    return 0;
}
