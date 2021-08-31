
############################	TYPE OF CONSTANT AND POINTERS	##########################


1. const char *p = "ABC"		--> "ABC" datas� de�i�tirilemez, Pointer de�i�tirilebilir.
	
	# *p = 'Z'		--> Compiler hata verir ��nk� *p ABC'ye e�ittir.
	# p++			--> OK, ��nk� pointer adresi de�i�tirilebilir.
	

2. char *const p = "ABC"		--> "ABC" de�i�tirilebilir, Pointer sabittir.

	# *p = 'Z'		--> OK, ��nk� data de�i�tirilebilir.
	# p++			--> Compile hata verir ��nk� Pointer adresi sabittir.
	

3. const char *const p = "ABC"	--> Ne "ABC" ne de pointer de�erleri de�i�tirilemez.

	# *p = 'Z'		--> Compile hata verir ��nk� data sabittir.
	# p++			--> Compile hata verir ��nk� Pointer adresi sabittir.
	

-------	NOT --------

const de�i�ken tipinin �n�ne veya arkas�na gelebilir.
	
	�RNEK;
		const char == char const;
		

###############################		CASTING		##########################

--> Bug�ne kadar kulland���n y�ntem �ok eski bir y�ntem. Art�k 4 farkl� tipte tan�mlama yap�l�yor. Bunlar; static_cast, const_cast, reinterpret_cast, dynamic_cast ' tir.

	1. static_cast;
		
		# static_cast<type>(de�i�ken)
		# Bir tipten kabul edilebilecek ba�ka bir tip d�n���m� yapar.
	
		
	2. const_cast;
		
		# const_cast<type>(de�i�ken)
		# Constant bir datay� g�steren pointer'lar aras�nda de�i�iklik yapmak i�in kullan�l�r. As�l kullan�m yeri constant datalar�n d�n���mlerindedir.
		
			�RNEK;
				�lk a�amada q ile p pointerlar�n�n de�erleri e�itlenmeye �al���l�yor fakat izin veirlmiyor.
				
				const char *p = "ABC";			--> Pointer Sabit bir datay� g�steriyor.
				char *q;						
				q = p;							--> Compiler hata verir ��nk� sabit data de�i�ime u�rayabilir.
				
				�kinci a�amada ise sabit bir datay� g�steren p pointer�, q pointer�na e�itleniyor. Daha sonradan ise constant datan�n de�i�ebilmesi sa�lan�yor.
				q = const_cast<char *>(p);		--> Uygun �ekilde tip d�n���m� yap�l�yor.
				*q = p;							--> Boom! Dangerous??
				
	3. reinterpret_cast;
	
		# reinterpret_cast<type>(de�i�ken)
		# Anlamad�m.......... Muhtemelen de�iken t�rlerini yeniden yorumlay�p, istenilen tipe d�n���mde kullan�l�yor.
		
	4. dynamic_cast;
	
		# �leriki derslerde bu konu �zerinde durulacak.
		

############################	DYNAMIC MEMORY ALLOCATION	##########################

--> malloc ve free fonksiyonlar� yerine new ve delete fonksiyonlar� gelmi�tir. 
--> Bu fonksiyonlar�n kullan�m� daha kolay olmakla birlikte her t�rden tip/de�i�ken i�in kullan�labilir.

	�RNEK;
		int *p;
		p = new int;				# int(5) --> 5 say�s�n� olu�turur. int[5] --> 5 tane int say� olu�turur.
		......						# new smth;  smth --> struct, class, type vs olabilir.
		delete p;
		

############################	INLINE FUNCTIONS	##########################

--> Normal fonksiyonlar derlendi�inde makina diline d�n��t�r�l�r ve stackte saklan�r fakat inline fonksiyonlar� programda her kullan�lan yere ayr� ayr� kopyalan�r.
--> Bu program�n boyutunun artmas�na fakat daha h�zl� �al��mas�na sebep olur. 
--> Normal fonksiyonlar her �a�r�ld���nda i�lemci o fonksiyona dallan�r ve i�i bitince geri gelir. Fakat inline fonksiyonlar�nda kod d�md�z devam eder.
--> Makrolar en h�zl� �al��an kodlar olmas�na ra�men debug gibi i�lemlere uygun olmad��� i�in her zaman tavsiye edilmez.
--> �ok uzun fonksiyonlarda inline fonksiyonlar� pek tercih edilmez ��nk� h�z ve depolama verimlili�i d��er.

	�RNEK;
		void f (char c int i1 = 0,int i2 = 1)		--> 2. veya 3.parametre girilmedi�i zaman default olarak bu de�erler i�leme tabi tutulur.
		void f (char cint i1 = other_func ())		--> Ayn� zamanda bu �ekilde bir kullan�m da vard�r.
		
		
############################	OTHERS NOTES	##########################

--> C++ ayn� isimde birden fazla fonksiyon olu�turulmas�n� destekler. Fakat fonksiyon parametre say� ve tipleri farkl� olmak zorundad�r.
--> & operat�r� ile bir adres blo�una iki veya daha fazla de�i�ken ismi atanabilir. �RNEK; int &j = i; 		--> i daha �nceden tan�mlanm�� olmal�d�r.
--> Call by reference y�nteminde pointer yollay�p onlarla i�lem yapmak yerine & operat�r� ile yollan�p normal i�lemler yap�labilir. (Slayt 2.26)
--> Bir fonksiyona parametre olarak data yollanaca��na, (const data &x) �eklinde data adrasi yollan�r bu sayede depolamada ciddi avantaj sa�lan�r. 44 byte yerine 4 byte.

