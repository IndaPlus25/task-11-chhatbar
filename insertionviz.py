import pygame
import time
pygame.init()

SCREEN_WIDTH = 1200
SCREEN_HEIGHT = 800
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Insertion Sort")

A = [5, 2, 9, 1, 5, 6]

BAR_WIDTH = 50
BAR_GAP = 20
START_X = 50
START_Y = SCREEN_HEIGHT - 50
MAX_VALUE = max(A)
SCALE = (SCREEN_HEIGHT-100)/MAX_VALUE

pygame.font.init()
FONT = pygame.font.SysFont('Arial', 30)

def draw_bars(screen, A, current_i, current_j):
    screen.fill(BLACK)

    for index, value in enumerate(A):
        height = value * SCALE
        x = START_X + index * (BAR_WIDTH + BAR_GAP)
        y = START_Y - height
        colour = BLUE
        if index == current_i:
            colour = RED
        elif index == current_j and current_j >= 0:
            colour = GREEN
        elif index == -1:
            colour = WHITE
        bar_rect = pygame.Rect(x, y, BAR_WIDTH, height)
        pygame.draw.rect(screen, colour, (x, y, BAR_WIDTH, height))

def insertion_sort(A): 
    n = len(A)
    for i in range(1, n):
        x = A[i]
        j = i - 1
        
        yield A, i, j 

        while j >= 0 and x < A[j]:
            A[j + 1] = A[j] 
            j -= 1
            yield A, i, j 

        A[j + 1] = x
        
        yield A, i, -1 
        
    yield A, -1, -1 
    return

sort_gen = insertion_sort(A)
current_i = -1
current_j = -1
is_sorting = True
DELAY = 0.5

clock = pygame.time.Clock()
last_step_time = time.time()

run = True
while run:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
    
    if is_sorting and (time.time() - last_step_time) > DELAY:
        try: 
            _, current_i, current_j = next(sort_gen)
            last_step_time = time.time()
        except StopIteration:
            is_sorting = False
        last_step_time = time.time()
    draw_bars(screen, A, current_i, current_j)
    pygame.display.flip()

pygame.quit()
       