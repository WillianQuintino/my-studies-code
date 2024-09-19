import cv2
import numpy as np

# Função para desenhar uma estrela usando cinco pontos
def draw_star(image, points):
    for i in range(len(points)):
        next_index = (i + 2) % len(points)  # Pula um ponto para formar a estrela
        cv2.line(image, points[i], points[next_index], (255, 0, 0), 2)

# Função principal
def main():
    # Acessar a webcam (0 é o índice da webcam padrão)
    cap = cv2.VideoCapture(0)

    # Verificar se a webcam foi aberta corretamente
    if not cap.isOpened():
        print("Erro ao abrir a webcam.")
        return

    # Definir uma resolução mais baixa para aumentar a velocidade
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

    # Criar um objeto VideoWriter para salvar o resultado
    fourcc = cv2.VideoWriter_fourcc(*'XVID')
    out = cv2.VideoWriter('video_saida.avi', fourcc, 30.0, (640, 480))

    while True:
        ret, frame = cap.read()
        if not ret:
            break  # Sai do loop se não houver mais quadros

        # Converter para escala de cinza e aplicar desfoque
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
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
                cv2.circle(frame, center, radius, (0, 255, 0), 2)  # Desenhar o círculo

            # Desenhar a estrela se houver pelo menos 5 centros
            if len(centers) == 5:
                draw_star(frame, centers)

        # Escrever o quadro processado no vídeo de saída
        out.write(frame)

        # Mostrar o quadro processado (opcional)
        cv2.imshow('Video', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Liberar os objetos
    cap.release()
    out.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
