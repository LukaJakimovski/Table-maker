# Table-maker

std::cout : print the following message                                                                                                                         
std::cin  : take in input                                                                                                                                       
//        : comment                                                                                                                                             
\t        : tab                                                                                                                                                 
\n        : endline                                                                                                                                             
base + rateOfChange * (i ou index)  :    y = b + mx



"std" a namespace. The "::" operator is the "scope" operator. It tells the compiler which class/namespace to look in for an identifier.

So std::cout tells the compiler that you want the "cout" identifier, and that it is in the "std" namespace.

If you just said cout then it will only look in the global namespace. Since cout isn't defined in the global namespace, it won't be able to find it, and it will give you an error.


using namespace std; tell the compiler "take everything that's in the std namespace and dump it in the global namespace". This allows you to use cout without the std:: prefix, but it increases the probability for name conflicts, since a bunch of extra names that you didn't expect also got added to the global namespace, and that might butt heads with some of your own names. 
