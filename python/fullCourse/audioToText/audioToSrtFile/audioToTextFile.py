import speech_recognition as sr
filename = "export.wav"
r = sr.Recognizer()
# open the file
with sr.AudioFile(filename) as source:
    # listen for the data (load audio to memory)
    audio_data = r.record(source)
    # recognize (convert from speech to text)
    text = r.recognize_google(audio_data)
    print(text)
    with open("audio5.txt","w") as f:
            f.write(text)
    with open("audio.srt","w") as f:
            f.write(text)