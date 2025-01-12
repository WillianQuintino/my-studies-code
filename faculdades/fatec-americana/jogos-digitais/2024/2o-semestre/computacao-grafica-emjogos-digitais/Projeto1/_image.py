import cv2
import numpy as np

# Função para desenhar uma estrela usando cinco pontos
def draw_star(image, points):
    for i in range(len(points)):
        next_index = (i + 2) % len(points)  # Pula um ponto para formar a estrela
        cv2.line(image, points[i], points[next_index], (255, 0, 0), 2)

# Função principal
def main():
    # Carregar a imagem
    image = cv2.imread('circulos.jfif')
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    blurred = cv2.GaussianBlur(gray, (9, 9), 2)

    # Detectar círculos
    circles = cv2.HoughCircles(blurred, cv2.HOUGH_GRADIENT, dp=1, minDist=30,
                                param1=100, param2=30, minRadius=0, maxRadius=0)

    # Se círculos foram encontrados
    if circles is not None:
        circles = np.uint16(np.around(circles))
        centers = []

        # Capturar até 5 centros de círculos
        for i in circles[0, :5]:  # Limitar a 5 círculos
            center = (i[0], i[1])
            centers.append(center)
            radius = i[2]
            cv2.circle(image, center, radius, (0, 255, 0), 2)  # Desenhar o círculo

        # Desenhar a estrela se houver pelo menos 5 centros
        if len(centers) == 5:
            draw_star(image, centers)

    # Salvar a imagem com círculos e a estrela
    cv2.imwrite('resultado.jpg', image)

    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
