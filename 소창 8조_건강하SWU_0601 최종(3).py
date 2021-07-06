Python 3.9.2 (tags/v3.9.2:1a79785, Feb 19 2021, 13:44:55) [MSC v.1928 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> import matplotlib.pyplot as plt #matplotlib-데이터를 도식화할 수 있도록하는 라이브러리,pyplot- 속한 모듈 
import matplotlib.ticker as ticker
import datetime         # datetime, time 모듈 이용해 시간 다루기
import time     
import winsound      # 윈도우용 소리 재생 모듈로 알림음 사용
                                    
def start_menu():                    #첫 시작 화면 함수 정의
    menu=[(1,'약 먹을 시간'),
      (2,'혈당 기록'),
      (3,'운동시간 기록'),
      (4,'오늘의 감정 일기'),
      (5,'종료')]
    for i,n in menu:
        print(i,n)
def list():                                 #5번 오늘의 감정 일기- 입력한 날짜와 그에 해당하는 기분을 출력하는 함수 
        for i,k in zip(date,emotion):
            print(i,k)
def ending():
        emotion.append(feel_input)            #5번 오늘의 감정 일기- 기분을 리스트에 추가하고 끝내는 문장을 출력하는 함수
        print(" 오늘도 수고했습니다.")
        print("_____________________")

def check_alarm_input(alarm_time):     # 알람 시간 체크
	if len(alarm_time) == 1: 
		if alarm_time[0] < 24 and alarm_time[0] >= 0:
			return True
	if len(alarm_time) == 2: 
		if alarm_time[0] < 24 and alarm_time[0] >= 0 and \
		   alarm_time[1] < 60 and alarm_time[1] >= 0:
			return True
	elif len(alarm_time) == 3: 
		if alarm_time[0] < 24 and alarm_time[0] >= 0 and \
		   alarm_time[1] < 60 and alarm_time[1] >= 0 and \
		   alarm_time[2] < 60 and alarm_time[2] >= 0:
			return True
	return False
        
while True:
    start_menu()    #첫 시작 화면
    start_ans=int(input("숫자를 입력하세요: "))
    if(start_ans==1):    # 알람 프로그램 실행
        print("알람을 울릴 시간(예시 - 13:15:00)을 입력하세요.")
        while True:
            alarm_input=input(">> ")
            try:
                alarm_time=[int(n) for n in alarm_input.split(":")]
                if check_alarm_input(alarm_time):
                    break
                else:
                    raise ValueError
            except ValueError:
                print("ERROR: 시간을 HH:MM or HH:MM:SS 형식으로 입력해주세요.")  # 형식에 맞지 않는 값 입력시 출력
        message=input("약 종류를 입력하세요. : ")
        seconds_hms=[3600,60,1]
        alarm_seconds=sum([a*b for a,b in zip(seconds_hms[:len(alarm_time)], alarm_time)])
        now=datetime.datetime.now()
        current_time_seconds = sum([a*b for a,b in zip(seconds_hms, [now.hour, now.minute, now.second])])
        time_diff_seconds=alarm_seconds-current_time_seconds

        if time_diff_seconds<0:     # 남은 시간이 0초 미만일 경우 다음 날에 알람 설정
            time_diff_seconds+=86400

        print("\n알람이 %s 후에 울립니다."%datetime.timedelta(seconds=time_diff_seconds))
        time.sleep(time_diff_seconds)

        print("\n\n알람이 울렸습니다.\n\n")
        print(message,"복용할 시간입니다.")
        winsound.Beep(5000,3000)

    if(start_ans==2):
        date1=[]
        blood=[]
        while True:
            print(" 1.입력     2. 종료\n")
            ans1=int(input("숫자를 입력하세요:  "))
            if(ans1==1):
                date1_input=input("날짜를 입력하세요(00-XX-YY): ")
                blood_input=input("혈당 수치를 입력하세요: ")
                if not date1_input or not blood_input:
                    print("아무것도 입력되지 않았습니다")
                else:
                    date1.append(date1_input)
                    blood.append(blood_input)
            if(ans1==2):
                break
        plt.rcParams["font.family"] = u'Malgun Gothic'
        plt.rcParams['axes.unicode_minus']=False
        if not date1 or not blood:
            print("아무것도 입력되지 않았습니다.")
        else:
            
            plt.plot(date1, blood,marker='o', color='red')
            plt.title("날짜별 혈당수치")
            plt.xlabel("날짜")
            plt.ylabel("혈당수치")
            plt.show()

    if(start_ans==3):
        date2=[]
        exercise=[]
        while True:
            print(" 1.입력     2. 종료\n")
            ans2=int(input("숫자를 입력하세요:  "))
            if(ans2==1):
                date2_input=input("날짜를 입력하세요(00-XX-YY): ")
                exercise_input=input("운동시간을 입력하세요: ")
                if not date2_input or not exercise_input:
                    print("아무것도 입력되지 않았습니다.")
                else:    
                    date2.append(date2_input)
                    exercise.append(exercise_input)
            if(ans2==2):
                    break
        plt.rcParams["font.family"] = u'Malgun Gothic' #그래프에 한글폰트적용
        plt.rcParams['axes.unicode_minus']=False #그래프에서 한글깨짐방지
        if not date2 or not exercise:
            print("아무것도 입력되지 않았습니다")
        else:    
            plt.plot(date2, exercise,marker='o', color='red') #x축에 날짜, y축에 운동시간
            plt.title("날짜별 운동시간")
            plt.xlabel("날짜")
            plt.ylabel("운동시간(Hour)")
            plt.show()

                
    if(start_ans==4):                         #while True문과 if문을 통해 그날 그날의 기분과 일기를 작성할 수 있는 기능 구현
        date=[]      #날짜를 저장하는 배열
        emotion=[]   #그에 따른 기분을 저장하는 배열 선언 
        count1= count2= count3= count4=count5=count6=0    #카운트횟수 초기화 
        print("========Menu=======\n")
        print("     1. 평온     \n")
        print("     2. 행복     \n")
        print("     3. 신남 \n")
        print("     4. 슬픔     \n")
        print("     5. 화남     \n")
        print("     6. 한줄일기     \n")
        print("===================")
        while True:
            print("              <START>\n")
            print(" 1. 입력     2. 수정    3. 종료 \n")     
            ans=int(input("숫자를 입력하세요:  "))
            if(ans==1):
                date_input=input("날짜를 입력하세요.YY-MM-DD\n")      #1을 입력했을 때-데이터를 입력
                date.append(date_input)
                feel_input=input(" 오늘 하루 어땠나요?")
                if(feel_input=="평온"):
                    ending()
                    count1+=1
                if(feel_input=="행복"):
                    ending()
                    count2+=1
                if(feel_input=="신남"):
                    ending()            
                    count3+=1
                if(feel_input=="슬픔"):
                    ending()
                    count4+=1
                if(feel_input=="화남"):
                    ending()
                    count5+=1
                if(feel_input=="한줄일기"):                   #주피터파일에 텍스트파일이 자동으로 생성 
                    print("     <한줄 일기작성>")
                    name=input("일기 제목: \n")
                    fileA=open(name,"w")
                    contents=input("내용: \n")
                    fileA.write(contents)
                    fileA.close()
                    print("파일이 저장되었습니다.")
                list()        #기분을 입력할 때마다 타임라인 형식으로 출력
            if(ans==2):                                              #2를 입력했을 때- 배열의 내용을 수정 
                num=int(input("순서를 입력하세요: "))          
                remove_date=input("날짜를 다시 입력하세요. YY-MM-DD: \n")
                remove_constant=input("내용을 다시 입력하세요: \n")
                if(emotion[num-1]=='평온'):                #기존에 카운트 되었던 횟수에서 한 번을 제외
                    count1=count1-1
                if(emotion[num-1]=='행복'):
                    count2=count2-1
                if(emotion[num-1]=='신남'):
                    count3=count3-1
                if(emotion[num-1]=='슬픔'):
                    count4=count4-1
                if(emotion[num-1]=='화남'):
                    count5=count5-1
                date[num-1]=remove_date
                emotion[num-1]=remove_constant      #변경된 횟수를 추가함 
                if(remove_constant=='평온'):                
                    count1=count1+1
                if(remove_constant=='행복'):
                    count2=count2+1
                if(remove_constant=='신남'):
                    count3=count3+1
                if(remove_constant=='슬픔'):
                    count4=count4+1
                if(remove_constant=='화남'):
                    count5=count5+1
                list()
            if(ans==3):  #그래프 출력과 함께 종료
                break    
        if(len(date)==0):  #아무것도 입력하지 않고 종료를 선택했을 때
                 print("아무것도 입력되지 않았습니다. ")
        if(len(date)!=0):   #각 기분의 비율을 계산하고 원 그래프 출력 
            ratio=[count1,count2, count3, count4,count5]   #카운트된 횟수들을 백분율로 계산 
            plt.title("Emotion Pie", fontsize=20)
            labels=["calmness","happiness","excited","sadness","anger"]  #범례 설정
            colors = ['#ff9999', '#ffc000', '#8fd9b6', '#d395d0','#A9BCF5']  #그래프 색상 설정 
            wedgeprops={'width': 0.7, 'edgecolor': 'w', 'linewidth': 5}
            plt.pie(ratio,startangle=0,autopct='%0.2f%%',counterclock=False,colors=colors,wedgeprops=wedgeprops)  #비율 표시,소수점 한자리까지 표시,시계방향으로 표시,가운데가 빈 그래프 표시
            plt.legend(labels,loc=(1.0, 0.5))     #범례 위치 설정
            plt.show()

    if(start_ans==5):
        print("프로그램을 종료합니다.")
        break
