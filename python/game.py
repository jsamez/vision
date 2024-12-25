import sys
from random import randint
from PySide6.QtCore import Qt, QTimer, QRectF
from PySide6.QtGui import QPainter, QColor
from PySide6.QtWidgets import QApplication, QWidget


class AirplaneGame(QWidget):
    def __init__(self):
        super().__init__()

        # 창 크기 설정
        self.setWindowTitle("Airplane Game")
        self.setGeometry(100, 100, 800, 600)

        # 비행기 속성
        self.airplane_x = 370
        self.airplane_y = 500
        self.airplane_width = 60
        self.airplane_height = 60
        self.airplane_speed = 5

        # 총알 속성
        self.bullets = []
        self.bullet_speed = 7

        # 괴물 속성
        self.monsters = []
        self.monster_speed = 2
        self.missed_monsters = 0
        self.max_missed_monsters = 5

        # 게임 상태
        self.game_over = False

        # 타이머 설정 (게임 루프)
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.game_loop)
        self.timer.start(30)  # 30밀리초마다 게임 루프 실행

        # 키 입력 관리
        self.left_pressed = False
        self.right_pressed = False
        self.space_pressed = False

    def game_loop(self):
        if self.game_over:
            return

        # 비행기 움직임
        if self.left_pressed and self.airplane_x > 0:
            self.airplane_x -= self.airplane_speed
        if self.right_pressed and self.airplane_x < self.width() - self.airplane_width:
            self.airplane_x += self.airplane_speed

        # 총알 움직임
        for bullet in self.bullets:
            bullet["y"] -= self.bullet_speed

        # 괴물 움직임
        for monster in self.monsters:
            monster["y"] += self.monster_speed

        # 괴물이 바닥에 닿았는지 확인
        for monster in self.monsters[:]:
            if monster["y"] > self.height():
                self.monsters.remove(monster)
                self.missed_monsters += 1
                if self.missed_monsters >= self.max_missed_monsters:
                    self.game_over = True

        # 총알이 괴물과 충돌했는지 확인
        for bullet in self.bullets[:]:
            for monster in self.monsters[:]:
                if bullet["x"] < monster["x"] + monster["width"] and bullet["x"] + 5 > monster["x"] and bullet["y"] < monster["y"] + monster["height"] and bullet["y"] + 10 > monster["y"]:
                    self.bullets.remove(bullet)
                    self.monsters.remove(monster)
                    break

        # 화면 밖으로 나간 총알 제거
        self.bullets = [bullet for bullet in self.bullets if bullet["y"] > 0]

        # 괴물 추가
        if randint(1, 100) <= 3:  # 3% 확률로 새로운 괴물 추가
            self.monsters.append({
                "x": randint(0, self.width() - 40),
                "y": 0,
                "width": 40,
                "height": 40
            })

        # 괴물이 점점 더 빠르게 내려옴
        self.monster_speed += 0.001

        # 화면 갱신 (페인팅 호출)
        self.update()

    def paintEvent(self, event):
        painter = QPainter(self)

        # 배경 그리기
        painter.setBrush(QColor(135, 206, 235))  # 하늘색
        painter.drawRect(self.rect())

        if self.game_over:
            # 게임 오버 화면 그리기
            painter.setBrush(QColor(0, 0, 0, 150))
            painter.drawRect(self.rect())
            painter.setPen(QColor(255, 0, 0))
            painter.setFont(painter.font())
            painter.drawText(self.rect(), Qt.AlignCenter, "GAME OVER")
            return

        # 비행기 그리기
        painter.setBrush(QColor(255, 0, 0))  # 빨간색 비행기
        airplane_rect = QRectF(self.airplane_x, self.airplane_y, self.airplane_width, self.airplane_height)
        painter.drawRect(airplane_rect)

        # 총알 그리기
        painter.setBrush(QColor(0, 0, 0))  # 검정색 총알
        for bullet in self.bullets:
            bullet_rect = QRectF(bullet["x"], bullet["y"], 5, 10)
            painter.drawRect(bullet_rect)

        # 괴물 그리기
        painter.setBrush(QColor(0, 255, 0))  # 초록색 괴물
        for monster in self.monsters:
            monster_rect = QRectF(monster["x"], monster["y"], monster["width"], monster["height"])
            painter.drawRect(monster_rect)

    def keyPressEvent(self, event):
        # 키 입력 처리 (비행기 이동, 총알 발사)
        if event.key() == Qt.Key_Left:
            self.left_pressed = True
        elif event.key() == Qt.Key_Right:
            self.right_pressed = True
        elif event.key() == Qt.Key_Space:
            # 스페이스바로 총알 발사
            self.bullets.append({
                "x": self.airplane_x + self.airplane_width / 2 - 2.5,
                "y": self.airplane_y
            })

    def keyReleaseEvent(self, event):
        # 키를 뗐을 때 처리
        if event.key() == Qt.Key_Left:
            self.left_pressed = False
        elif event.key() == Qt.Key_Right:
            self.right_pressed = False


if __name__ == "__main__":
    app = QApplication(sys.argv)

    game = AirplaneGame()
    game.show()

    sys.exit(app.exec())
