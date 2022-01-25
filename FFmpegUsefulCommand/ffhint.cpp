// g++ -fexec-charset=GBK ffhint.cpp -o ffhint.exe
#include <stdio.h>
#include <windows.h>

#define HINT_0 "\
简介\n\
1. 使用ffprobe -i input.mp4可以查看视频信息，包括分辨率、视频码率、音频码率、视频编解码格式、音频编解码格式等\n\
2. 某些参数与输入和输出是相关的。如果设置在-i input.mp4前，则表示该参数作用于输入视频，否则作用于输出视频\n\
3. -vn表示不处理视频，-an表示不处理音频，即输出分别抹除视频、音频\n\
4. -vcodec/-c:v表示设置视频编解码器，-acodec/-c:a表示设置音频编解码器。如：-vcodec libx264 -acodec aac，copy表示沿用编解码格式\n\
5. 视频文件大小主要与码率有关；视频帧率一般在25-30之间，低于20会有明显的卡顿感\n\
6. 无损压缩。可参考H.264推荐分辨率与码率配置表。以对应码率进行压缩，可以几乎无损\n\
7. 有损压缩。方法一：根据目标文件大小，除以视频时长，计算出码率，设置码率进行压缩\n\
8. 有损压缩。方法二：ffmpeg -i input.mp4 -vcodec libx264 -preset veryslow -crf 28 output.mp4\n\
9. preset用于调节编码速度和质量的平衡，由快到慢为：ultrafast、superfast、veryfast、faster、fast、medium、slow、slower、veryslow\n\
10. tune用于配合视频类型和视觉优化参数，如果符合可设置，否则不设置：film（电影、真人类型）、animation（动画）\n\
11. crf用于控制视频质量，取值范围0~51。0为无损模式，数值越大，质量越差，文件越小。感官上18~28比较合理\n\
"

#define HINT_1 "\
FFmpeg常用命令\n\
视频格式转换：ffmpeg -i input.avi output.mp4\n\
提取音频：ffmpeg -i input.avi -vn output.mp3\n\
提取视频：ffmpeg -i input.avi -an output.mp4\n\
裁剪视频5s：ffmpeg -i input.avi -ss 00:00:15 -t 00:00:05 output.mp4\n\
设置帧率20fps：ffmpeg -i input.avi -r 20 output.mp4\n\
设置视频码率（比特率）7552kbps：ffmpeg -i input.avi -b:v 7552k output.mp4\n\
设置音频码率（比特率）128kbps：ffmpeg -i input.mp3 -b:a 128k output.mp3\n\
设置帧的大小（分辨率）1920x1080：ffmpeg -i input.avi -s 1920x1080 output.mp4\n\
设置视频编解码格式：ffmpeg -i input.avi -c:v libx264 -c:a aac output.mp4\n\
"

#define HINT_2 "\
H.264推荐分辨率与码率配置表\n\
Name（名称）、Resolution（分辨率）、Link（网速/Mbps）\n\
Bitrate（比特率/Mbps）、Video（视频码率/Kbps）、Audio（音频码率/Kbps）\n\
-------------------------------------------------------\n\
Name            Resolution   Link Bitrate   Video Audio\n\
-------------------------------------------------------\n\
240p               424x240    1.0    0.64     576    64\n\
360p               640x360    1.5    0.96     896    64\n\
432p               768x432    1.8    1.15    1088    64\n\
480p               848x480    2.0    1.28    1216    64\n\
480p HQ            848x480    2.5    1.60    1536    64\n\
576p              1024x576    3.0    1.92    1856    64\n\
576p HQ           1024x576    3.5    2.24    2176    64\n\
720p              1280x720    4.0    2.56    2496    64\n\
720p HQ           1280x720    5.0    3.20    3072   128\n\
1080p            1920x1080    8.0    5.12    4992   128\n\
1080p HQ         1920x1080   12.0    7.68    7552   128\n\
1080p Superbit   1920x1080    N/A   20.32   20000   320\n\
-------------------------------------------------------\n\
Name            Resolution   Link Bitrate   Video Audio\n\
-------------------------------------------------------\n\
240p               320x240    1.0    0.64     576    64\n\
360p               480x360    1.2    0.77     704    64\n\
480p               640x480    1.5    0.96     896    64\n\
480p HQ            640x480    2.0    1.28    1216    64\n\
576p               768x576    2.3    1.47    1408    64\n\
576p HQ            768x576    2.5    1.60    1536    64\n\
720p               960x720    3.0    1.92    1856    64\n\
720p HQ            960x720    4.0    2.56    2432   128\n\
1080p            1440x1080    6.0    3.84    3712   128\n\
1080p HQ         1440x1080    9.0    5.76    5632   128\n\
1080p Superbit   1440x1080    N/A   20.32   20000   320\n\
-------------------------------------------------------\n\
"

int main(){
	Sleep(500);
	// printf("%s\n", TEXT("请按任意键继续..."));
	// getchar();
	printf("%s\n", TEXT(HINT_0));
	printf("%s\n", TEXT(HINT_1));
	printf("%s\n", TEXT(HINT_2));
	printf("%s\n", TEXT("请按任意键继续..."));
	getchar();
	return 0;
}
