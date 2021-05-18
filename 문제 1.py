num=int(input("1. 수식 계산기 2. 두수 사이 합계 : "))
num1=0
num2=0
result=0

if (num== 1):
    result=input("*** 수식을 입력하세요 : ")
    print(result,"의 결과는 ", eval(result),"입니다.")
elif (num ==2):
    num1=int(input("*** 첫번째 숫자를 입력하세요: "))
    num2=int(input("*** 두번째 숫자를 입력하세요: "))
    for i in range(num1,num2+1,1):
       result=result+i

    print(num1,"+...+",num2,"는 ",result,"입니다.")
else:
    print("1 또는 2만 입력해야 합니다.")
##eval함수를 가지고 계산기 구현
##num1부터 num2까지 덧셈 계산 
