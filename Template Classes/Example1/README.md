# Example 1
Bu sınıfın iki üyesi olacaktır. Bunlardan birisi  timeStep  olacaktır. Diğeri ise, std::vector taşıyıcısında tutulan  datalar olacaktır. Böylece, bir datanın vektörde bulunduğu indeks timeStep ile çarpıldığında grafikte datanın zamanını bulmuş olursunuz.

-   timeStep ve datalar farklı tiplerde olabilmektedir. Örneğin, timeStep double iken, datalar float olabilir. timeStep int iken, datalar double olabilir vb.
-   Kurucu fonksiyonda, parametre olarak timeStep değeri verilmektedir.
-   addValue  adlı üye fonksiyonu, parametre olarak verilen değeri bir sonraki timeStep için grafiğe data eklemesini yapmaktadır.
-   getMax  üye fonksiyonu, grafikteki maksimum değeri döndürmektedir.
-   getMin  üye fonksiyonu, grafikteki minimum değeri döndürmektedir.
-   += üye operatör fonksiyonu, addValue gibi işlem yapmaktadır. Örneğin, Graph graph; graph+=5; yazdığınızda, 5 değeri yeni bir data olarak eklenmektedir.
# Sample Output![enter image description here](https://i.hizliresim.com/vZGUqV.png)
