## Ex4-OOP2
2nd year 2nd semester

תרגיל 4 - PIPE

אלישר פייג 302278338 
שגיא אביטל 305295826

הסבר כללי:

בתרגיל היה עלינו לממש משחק בגרפיקת SFML על פי חוקי משחק : PIPE
 
 במשחק מוצג לוח שעליו יהיו האלמנטים הבאים:
ברז (מקור) : S 
כיור ("בור"/ מטרה): T
צינור ישר: -
פינה: C
צומת: V
צומת ראשית: +

תיאור המשחק:

המשתמש, באמצעות לחיצות עכבר על האריחים המוצגים, צריך למצוא נתיב בין הברז לבין 
הכיור, כאשר כל לחיצה מסובבת את האריח ב90 מעלות.
מוצגות למשתמש מספר הלחיצות וכן מוצג הזמן (בשניות)

מטרת המשחק-
למצוא נתיב בין הברז לכיור

 תיכון (Desing):

המשחק מנוהל ע"י GameMangaer בשיתוף עם Board
המשחק מחולק למחלקות הבאות:

GameMangaer
Board
Image (Singleton)
Sounds (Singleton)
Utilities.h
GameObject <|-- Tap
GameObject <|-- Sink
GameObject <|-- Pipe
GameObject <|-- Corner
GameObject <|-- Section
GameObject <|-- MainSection
GameObject <|-- Empty

רשימת הקבצים שיצרנו ותכונותיהן:

GameMangaer.h/cpp
מנהל את המשחק מלמעלה ואת הצג המוצג לנו בחלון ע"י המחלקות האחרות. הוא אחראי לניהול
החלונות והתקשורת עם הבורד

Board.h/cpp 
מחלקת הלוח היא המחלקה אשר אחראית על פתיחת הקןבץ והחזקת הנתונים המתקבלים
מתוך הקובץ והחזקת האובייקטים בוקטורים מתאימים. הנתונים משתנים בהתאם למשחק
ומתעדכנים בבורד אשר מדבר עם שאר המחלקות ומעדכן את הGameManager במקרים
החריגים של מעבר שלב, הפסד, גודל הלוח החדש, המיקומים החדשים בכל סבב בלולאה (כי 
הגייםמאנאג'ר מצייר על הלוח) וכדומה..  

Image.h/cpp
מחלקת singleton .
אחראית על טעינת התמונות של המשחק ושמירתן בוקטור מתאים

Sounds.h/cpp
מחלקת singleton .
אחראית על טעינות של הצלילים למשחק ושמירתם בוקטור מתאים
בנוסף, קיימת לה פונקציה makeSound() אשר בקריאה מכל מקום בתוכנית
בשליחת קונסט מתאים מנגנת את הצליל הנדרש (נגיד בהתנגשות או בסיום שלב וכד')
וכן פונקצייה stopSound

GameObject.h/cpp 
מחלקה זו היא זו שמחזיקה את הנתונים של ה Sprite עבור כל אובייקט. ממנה יורשות האובייקטים

Tap.h/cpp
אחראית על הברז

Sink.h/cpp
אחראית על הצינור

Pipe.h/cpp
אחראית על הצינור הישר

Corner.h/cpp
אחראית על ה"פינות"

Section.h/cpp
אחראית על הצמתים

MainSection.h/cpp
אחראית על הצמתים הראשיים

מבני נתונים:

vector < string > m_charBoard
שמירה של השלב הנוכחי מבחינת charים

vector < vector < shared_ptr < GameObject >> m_objects
שומר את האובייקטים 
בחרנו להשתמש בוקטור של וקטור כדי שיהיה ניתן למצוא שכנויות בקלות ע"י אינדקסים (כמו שבנוי הלוח) 

פורמט הקובץ:

Board.txt
מדובר בקובץ בודד, כל שלב מופרד מהשלב האחר בשורה ריקה. לא נדרשות פעולות 
בין כל שלב (שומר בכל שלב את המיקום הנוכחי של תחילת השלב למקרה של פסילה,
ובמקרה של ניצחון אוכל את השורה הריקה ומתקדם לייצוג של השלב הבא ושומר באותו
אופן את תחילת השלב הנוכחי וכך הלאה.)
אלגוריתמים הראויים לציון:
**********************************************************
ירושה ופולימורפיזם, מצביעים חכמים, טיפול בחריגות , רנג' פור לופ,
 רקורסיה למציאת השכנים בזמן אמת
***********************************************************

באגים ידועים:
.אין
