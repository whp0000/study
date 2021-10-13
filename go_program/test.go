package main

import "fmt"

func main() {
    var a int = 1
    var str string = "aa"
    fmt.Printf("%d,%s\n",a,str)
    fmt.Printf("%v,%v\n",a,str)
    if a==1 {
        fmt.Printf("true\n")
    } else {
        
        fmt.Printf("false\n")
    }

    var x interface{}

    switch i := x.(type) {
      case nil:
         fmt.Printf(" x 的类型 :%T\n",i)
      case int:
         fmt.Printf("x 是 int 型")
      case float64:
         fmt.Printf("x 是 float64 型")
      case func(int) float64:
         fmt.Printf("x 是 func(int) 型")
      case bool, string:
         fmt.Printf("x 是 bool 或 string 型" )
      default:
         fmt.Printf("未知型")
   }

   count := 5
   for count > 0{
        fmt.Printf("%v\n",count)
        count--
   }
    for i:=0; i<10; i++ {
    
        fmt.Printf("%v\n",i)
        if i == 6 {
            break
        }

    }

    var name1 string = "wang"
    var name2 string = "hai"
    name1,name2 = swap(name1,name2)
    fmt.Println(name1,name2)
    


}

func swap(x,y string) (string,string){
    return y,x
}
