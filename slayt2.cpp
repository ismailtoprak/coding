
############################	TYPE OF CONSTANT AND POINTERS	##########################


1. const char *p = "ABC"		--> "ABC" datasý deðiþtirilemez, Pointer deðiþtirilebilir.
	
	# *p = 'Z'		--> Compiler hata verir çünkü *p ABC'ye eþittir.
	# p++			--> OK, Çünkü pointer adresi deðiþtirilebilir.
	

2. char *const p = "ABC"		--> "ABC" deðiþtirilebilir, Pointer sabittir.

	# *p = 'Z'		--> OK, Çünkü data deðiþtirilebilir.
	# p++			--> Compile hata verir çünkü Pointer adresi sabittir.
	

3. const char *const p = "ABC"	--> Ne "ABC" ne de pointer deðerleri deðiþtirilemez.

	# *p = 'Z'		--> Compile hata verir çünkü data sabittir.
	# p++			--> Compile hata verir çünkü Pointer adresi sabittir.
	

-------	NOT --------

const deðiþken tipinin önüne veya arkasýna gelebilir.
	
	ÖRNEK;
		const char == char const;
		

###############################		CASTING		##########################

--> Bugüne kadar kullandýðýn yöntem çok eski bir yöntem. Artýk 4 farklý tipte tanýmlama yapýlýyor. Bunlar; static_cast, const_cast, reinterpret_cast, dynamic_cast ' tir.

	1. static_cast;
		
		# static_cast<type>(deðiþken)
		# Bir tipten kabul edilebilecek baþka bir tip dönüþümü yapar.
	
		
	2. const_cast;
		
		# const_cast<type>(deðiþken)
		# Constant bir datayý gösteren pointer'lar arasýnda deðiþiklik yapmak için kullanýlýr. Asýl kullaným yeri constant datalarýn dönüþümlerindedir.
		
			ÖRNEK;
				Ýlk aþamada q ile p pointerlarýnýn deðerleri eþitlenmeye çalýþýlýyor fakat izin veirlmiyor.
				
				const char *p = "ABC";			--> Pointer Sabit bir datayý gösteriyor.
				char *q;						
				q = p;							--> Compiler hata verir çünkü sabit data deðiþime uðrayabilir.
				
				Ýkinci aþamada ise sabit bir datayý gösteren p pointerý, q pointerýna eþitleniyor. Daha sonradan ise constant datanýn deðiþebilmesi saðlanýyor.
				q = const_cast<char *>(p);		--> Uygun þekilde tip dönüþümü yapýlýyor.
				*q = p;							--> Boom! Dangerous??
				
	3. reinterpret_cast;
	
		# reinterpret_cast<type>(deðiþken)
		# Anlamadým.......... Muhtemelen deðiken türlerini yeniden yorumlayýp, istenilen tipe dönüþümde kullanýlýyor.
		
	4. dynamic_cast;
	
		# Ýleriki derslerde bu konu üzerinde durulacak.
		

############################	DYNAMIC MEMORY ALLOCATION	##########################

--> malloc ve free fonksiyonlarý yerine new ve delete fonksiyonlarý gelmiþtir. 
--> Bu fonksiyonlarýn kullanýmý daha kolay olmakla birlikte her türden tip/deðiþken için kullanýlabilir.

	ÖRNEK;
		int *p;
		p = new int;				# int(5) --> 5 sayýsýný oluþturur. int[5] --> 5 tane int sayý oluþturur.
		......						# new smth;  smth --> struct, class, type vs olabilir.
		delete p;
		

############################	INLINE FUNCTIONS	##########################

--> Normal fonksiyonlar derlendiðinde makina diline dönüþtürülür ve stackte saklanýr fakat inline fonksiyonlarý programda her kullanýlan yere ayrý ayrý kopyalanýr.
--> Bu programýn boyutunun artmasýna fakat daha hýzlý çalýþmasýna sebep olur. 
--> Normal fonksiyonlar her çaðrýldýðýnda iþlemci o fonksiyona dallanýr ve iþi bitince geri gelir. Fakat inline fonksiyonlarýnda kod dümdüz devam eder.
--> Makrolar en hýzlý çalýþan kodlar olmasýna raðmen debug gibi iþlemlere uygun olmadýðý için her zaman tavsiye edilmez.
--> Çok uzun fonksiyonlarda inline fonksiyonlarý pek tercih edilmez çünkü hýz ve depolama verimliliði düþer.

	ÖRNEK;
		void f (char c int i1 = 0,int i2 = 1)		--> 2. veya 3.parametre girilmediði zaman default olarak bu deðerler iþleme tabi tutulur.
		void f (char cint i1 = other_func ())		--> Ayný zamanda bu þekilde bir kullaným da vardýr.
		
		
############################	OTHERS NOTES	##########################

--> C++ ayný isimde birden fazla fonksiyon oluþturulmasýný destekler. Fakat fonksiyon parametre sayý ve tipleri farklý olmak zorundadýr.
--> & operatörü ile bir adres bloðuna iki veya daha fazla deðiþken ismi atanabilir. ÖRNEK; int &j = i; 		--> i daha önceden tanýmlanmýþ olmalýdýr.
--> Call by reference yönteminde pointer yollayýp onlarla iþlem yapmak yerine & operatörü ile yollanýp normal iþlemler yapýlabilir. (Slayt 2.26)
--> Bir fonksiyona parametre olarak data yollanacaðýna, (const data &x) þeklinde data adrasi yollanýr bu sayede depolamada ciddi avantaj saðlanýr. 44 byte yerine 4 byte.

