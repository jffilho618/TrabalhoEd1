from PIL import Image

def txt_from_image_rgb(image_path, output_path):
    img = Image.open(image_path)
    largura, altura = img.size
    pixels = list(img.getdata())
    
    try:
        with open(output_path, 'w') as file:
            file.write(f"{largura}\n")
            file.write(f"{altura}\n")
            for y in range(altura):
                for x in range(largura):
                    pixel = pixels[y * largura + x]
                    file.write(f"{pixel[0]} {pixel[1]} {pixel[2]},")
                file.write("\n")
        print("Arquivo de texto criado com sucesso!")
    except Exception as e:
        print(f"Erro ao criar o arquivo de texto: {e}")

# Caminho da imagem
image_path = r"C:\Users\jffil\OneDrive\Documentos\ED1\Trabalho_2_avaliacao\TrabalhoEd1\galinha.jpg"

# Caminho para salvar o arquivo de texto
output_path = "imagem_convertida_rgb.txt"

# Converter imagem para arquivo de texto em RGB
txt_from_image_rgb(image_path, output_path)


def txt_from_image_gray(image_path, output_path):
    try:
        img = Image.open(image_path).convert('L')
        largura, altura = img.size
        pixels = list(img.getdata())
        
        with open(output_path, 'w') as file:
            file.write(f"{largura}\n")
            file.write(f"{altura}\n")
            for y in range(altura):
                for x in range(largura):
                    pixel = pixels[y * largura + x]
                    file.write(f"{pixel},")
                file.write("\n")
        
        print("Arquivo de texto em escala de cinza criado com sucesso!")
    except Exception as e:
        print(f"Erro ao criar o arquivo de texto: {e}")

# Caminho da imagem
image_path = r"C:\Users\jffil\OneDrive\Documentos\ED1\Trabalho_2_avaliacao\TrabalhoEd1\galinha.jpg"

# Caminho para salvar o arquivo de texto
output_path = "imagem_convertida_gray.txt"

# Converter imagem para arquivo de texto em escala de cinza
txt_from_image_gray(image_path, output_path)
