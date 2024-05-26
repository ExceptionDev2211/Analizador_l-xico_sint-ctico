mostrar("Declaración de variables: ");

variable a;
variable a = 10;

mostrar(a);

variable b = 10 % 2;
mostrar(b);

variable c = 30;
variable d = c + a;

mostrar(d);

variable e = d / a;

mostrar(e);

mostrar(e -- 10);

mostrar("Condicionales");

si(2<3){
    5+7;
}fins

variable aa = 0;
si(200 == 100){
    aa = 50; 
}fins
mostrar(aa);

variable bb;
si(100 == 100){
    bb = 50 + 50;
}fins
mostrar(bb);


variable dd;
si(50<20){
    dd = 300;
}sino{
    dd = 10;
}fins
mostrar(dd);

mostrar("Ciclo for");
variable ff = 2;
variable contador;
para(contador= 0;contador <= 10 ){
    ff = ff + 2;
}finp
mostrar(ff);

mostrar("Ciclo for 2");
variable gg = 2;
variable contador2;
para(contador2= 0;contador2 <= 10 ){
    gg = gg * 2;
}finp
mostrar(gg);

mostrar("Ciclo for 3");
variable jj = 50;
variable contador3;
para(contador3= 0;contador3 <= 10 ){
    jj = jj -- 2;
}finp
mostrar(jj);

mostrar("Ciclo for 5");
variable mm = 50;
variable contador5;
para(contador5= 1;contador5 <= 20 ){
    mm = mm / 2;
}finp
mostrar(mm);

mostrar("Ciclo while 1");

variable a1 = 10;
variable i1 = 0;
mientras(i1 < a1){
    a1 = a1 + 1;
}finw
mostrar(a1);

mostrar("Ciclo while 2");
variable a2 = 3;
variable b2 = 20;
variable i2 = 0;

mientras(i2 < a2) {
    b2 = b2 -- 5;
}finw
mostrar(b2);

mostrar("Funciones");
funcion f1(){
    variable cj7 = 10 + 20; 
devolver cj7;
}finf
mostrar(f1);

variable zz;
funcion f2(){si(2<3){
    zz = 5+7;
    }fins 
devolver zz;}finf
mostrar(zz);

variable mmm;
funcion f3(){
    si(5>3){
        mmm = 30*50;
    }fins 
 devolver mmm;}finf
mostrar(f3);

variable ii = 0;
variable lll = 30;
variable gato = 0;
funcion fwh(){
    mientras(ii < lll){
        gato = gato + 1;
    }finw
    devolver gato;
}finf

mostrar(fwh);

variable iii = 0;
variable ccc = 10;
funcion resta(){
    variable lkj = 50;
    mientras(iii < ccc){
        lkj = lkj -- 1;
    }finw
    devolver lkj;
}finf
mostrar(lkj);
mostrar("Errores");
intentar{} capturar {mostrar("Hola mundo");}fint
intentar{ 1/0 } capturar {mostrar("División por 0");}fint



