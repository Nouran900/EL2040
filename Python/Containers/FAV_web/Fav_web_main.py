import FAV_WEB as X

user_menu={
    "1.Google",
    "2.youtube",
    "3.github",
    "4.exit"
}
#print(type(user_menu))
print("hello,please choose a number from 1 to 4 based on the action you want:")
print(user_menu)
req=int(input("your choice:"))

if req==1:
    X.Firefox_take_url("https://www.google.com/")
elif req==2:
    X.Firefox_take_url("https://www.youtube.com/")
elif req==3:
    X.Firefox_take_url("https://github.com/")
else :
    print("well,have a nice day")    