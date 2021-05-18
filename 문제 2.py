foods={"떡볶이":"오뎅",
       "짜장면":"단무지",
       "라면":"김치",
       "피자":"피클",
       "맥주":"땅콩",
       "치킨":"치킨무",
       "삼겹살":"상추",
       }     

while True:
    keys=foods.keys()
    print(list(keys),end='')
    key=input("중 좋아하는 것은 ? "
              )
    if(key == "끝"):
        break
    if (key not in foods):
        print("그런 음식이 없네요 확인해 보세요.")
        continue
        
    print("<",key,">","궁합 음식은 ","<",foods.get(key),"> 입니다.")
    
    
