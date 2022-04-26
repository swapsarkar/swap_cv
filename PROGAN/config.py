import cv2
import torch
from math import log2

START_TRAIN_AT_IMG_SIZE = 64
DATASET = r'C:\Users\Madhumita\Downloads\archive\resized'
CHECKPOINT_GEN = "generator.pth"
CHECKPOINT_CRITIC = "critic.pth"
DEVICE = "cuda" if torch.cuda.is_available() else "cpu"
SAVE_MODEL = True
LOAD_MODEL = True
LEARNING_RATE = 1e-3
BATCH_SIZES = [16, 16, 16, 16, 16, 16, 16, 8, 4]
CHANNELS_IMG = 3
Z_DIM = 256  # was 512
IN_CHANNELS = 128  # was 512
CRITIC_ITERATIONS = 1
LAMBDA_GP = 10
PROGRESSIVE_EPOCHS = [20] * len(BATCH_SIZES)
FIXED_NOISE = torch.randn(8, Z_DIM, 1, 1).to(DEVICE)
NUM_WORKERS = 4
IMAGE_SIZE = 512
NUM_STEPS = (int(log2(IMAGE_SIZE / 4)) + 1)