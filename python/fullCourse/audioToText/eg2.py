from pydub import AudioSegment
sound = AudioSegment.from_mp3("test.mp3")
print("hello")
sound.export("file.wav", format="wav"