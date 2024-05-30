package main

import "fmt"

var mounth_day = [13]int{0,31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31}

func Ping_Run_Year(year int) int{
	if year % 100 == 0{
        if year % 400 == 0{
			return 1
		}else{
			return 0
		}
    }else{
        if year % 4 == 0{
			return 1
		}else{
			return 0
		}
    }
}

func First_Of_Month(year int, month int) int{
	var alldays int = 0
	for  i := 1 ; i < year ; i += 1{
        alldays += 365 + Ping_Run_Year(i)
    }
	for  i := 1 ; i < month ; i += 1{
        if i == 2{
            alldays += Ping_Run_Year(year)
        }
        alldays += mounth_day[i]
    }
	return (alldays+1) % 7
}

func Days(year int , month int) int{
	if month != 2{
        return mounth_day[month]
    }else{
        return 28+Ping_Run_Year(year)
    }
}


func main() {
	var year int 
	var month int
	fmt.Printf("input the year:")
	fmt.Scanln(&year)
	fmt.Printf("\ninput the month:")
	fmt.Scanln(&month)
	for{
		if !(year > 0 && month > 0 && month < 13){
			break
		}
		day := First_Of_Month(year,month)
		days := Days(year , month)
		fmt.Printf(" Sun Mon Tue Wed Thu Fir Sat  \n")
		for j := 0 ; j < day ; j += 1{
			fmt.Printf("    ")
		}
		for i := 1 ; i <= days ; i += 1{
			if day % 7 == 0{
				fmt.Printf("\n%4d",i)
			}else{
				fmt.Printf("%4d", i)
			}
			day += 1
		}
		fmt.Printf("\n")
		fmt.Printf("input the year:")
		fmt.Scanln(&year)
		fmt.Printf("\ninput the month:")
		fmt.Scanln(&month)
	}
}
