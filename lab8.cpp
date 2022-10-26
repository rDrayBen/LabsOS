#include <iostream>
#include <pthread.h>
#include <string>
#include <sys/resource.h>

int main()
{
     pthread_t thread1, thread2;
     int  iret1, iret2;

     //iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     //iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);

    
    int hThread = pthread_create(&thread1, NULL, NULL, NULL);
    std::cout << "Do you want to change the priority(y/n)?: ";
    char ans;
    std::cin >> ans;
    if(ans == 'y'){
        std::cout << "Choose priority(low, normal, high): ";
        std::string choise;
        std::cin >> choise;
        if(choise == "low"){
            setpriority(PRIO_PROCESS, NULL, 15);
        }else if(choise == "normal"){
            setpriority(PRIO_PROCESS, NULL, 0);
        }else if(choise == "high"){
            setpriority(PRIO_PROCESS, NULL, -20);
        }else{
            std::cout << "Input is incorrect\n";
        }
    }

    std::cout << "Open pages in browser?(y/n): ";
    std::cin >> ans;
    if(ans == 'y'){
        system("open https://www.google.com/search?q=wikipedia+english&client=firefox-b-lm&ei=50hZY6nFJNe0rgTV-4zgDA&oq=wikipedia+eng&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQARgAMgUIABCABDIFCAAQgAQyBQgAEIAEMgUIABCABDIFCAAQgAQyBQgAEIAEMgUIABCABDIFCAAQgAQyBQgAEIAEOgoIABBHENYEELADOgcIABCwAxBDSgQIQRgASgQIRhgAUMMFWN4MYJgcaAFwAXgAgAGEAYgBnAOSAQMzLjGYAQCgAQHIAQrAAQE&sclient=gws-wiz-serp");
        system("open https://duckduckgo.com/?t=ffab&q=wikipedia&ia=web");
        system("open https://www.bing.com/search?form=MOZLBR&pc=MOZI&q=wikipedia");
        system("open https://sg.search.yahoo.com/search;_ylt=Awrx_Z62SFljjswP_joi4gt.;_ylc=X1MDMjExNDcwODAwMgRfcgMyBGZyAwRmcjIDc2ItdG9wLXNlYXJjaARncHJpZANtN0owdGRZalJuLlFDWGxicklvdWtBBG5fcnNsdAMwBG5fc3VnZwMxMARvcmlnaW4Dc2cuc2VhcmNoLnlhaG9vLmNvbQRwb3MDMARwcXN0cgMEcHFzdHJsAzAEcXN0cmwDOQRxdWVyeQN3aWtpcGVkaWEEdF9zdG1wAzE2NjY3OTU2OTY-?p=wikipedia&fr=sfp&iscqry=&fr2=sb-top-search");  
    }
    pthread_join( hThread, NULL);
    
    
    
}

