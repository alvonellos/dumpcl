#include <stdio.h>
#include <stdlib.h>
#include <OpenCL/opencl.h>
//Authored by: Alexander Alvonellos
//         On: 07/26/12
// Platform:
//   Mac OSX 10.7.4
// Sources:
//   http://www.khronos.org/registry/cl/sdk/1.0/docs/man/xhtml/clGetDeviceInfo.html
//   http://www.khronos.org/files/opencl-quick-reference-card.pdf
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ullong;

int main(int argc, char* const argv[]) {
    cl_uint num_devices, i, j;
    clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices);

    cl_device_id* devices = calloc(sizeof(cl_device_id), num_devices);
    clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, num_devices, devices, NULL);

    char buf[128];
    fprintf(stdout, "Device Information for %u devices:\n", num_devices);
    for (i = 0; i < num_devices; i++) {
	for(j = 0; j < 10; j++) { printf("%s", "-");} printf("%u\n", i);	
        clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 128, buf, NULL);
        fprintf(stdout, "\tCL_DEVICE_NAME: %s\n", buf);

        clGetDeviceInfo(devices[i], CL_DEVICE_VERSION, 128, buf, NULL);
        fprintf(stdout, "\tCL_DEVICE_VERSION: %s\n", buf);
	
	cl_uint intbuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_ADDRESS_BITS, sizeof(intbuf), &intbuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_ADDRESS_BITS: %u\n", intbuf);

	cl_bool avail = CL_FALSE;
	clGetDeviceInfo(devices[i], CL_DEVICE_AVAILABLE, sizeof(avail), &avail, NULL);
        fprintf(stdout, "\tCL_DEVICE_AVAILABLE: %s\n", (avail == CL_TRUE) ? "TRUE" : "FALSE");

	clGetDeviceInfo(devices[i], CL_DEVICE_COMPILER_AVAILABLE, sizeof(avail), &avail, NULL);
        fprintf(stdout, "\tCL_DEVICE_COMPILER_AVAILABLE: %s\n", (avail == CL_TRUE) ? "TRUE" : "FALSE");

/* TODO: Fix this so that it works.
	clGetDeviceInfo(devices[i], CL_DEVICE_DOUBLE_FP_CONFIG, sizeof(avail), &avail, NULL);
        fprintf(stdout, "\tCL_DEVICE_DOUBLE_FP_CONFIG: %s\n", (avail == CL_TRUE) ? "TRUE" : "FALSE");
*/

	clGetDeviceInfo(devices[i], CL_DEVICE_ENDIAN_LITTLE, sizeof(avail), &avail, NULL);
        fprintf(stdout, "\tCL_DEVICE_ENDIAN_LITTLE: %s\n", (avail == CL_TRUE) ? "TRUE" : "FALSE");

	clGetDeviceInfo(devices[i], CL_DEVICE_ERROR_CORRECTION_SUPPORT, sizeof(avail), &avail, NULL);
        fprintf(stdout, "\tCL_DEVICE_ERROR_CORRECTION_SUPPORT: %s\n", (avail == CL_TRUE) ? "TRUE" : "FALSE");

/* TODO: Fix this so that it works. See Note 1:
	clGetDeviceInfo(devices[i], CL_DEVICE_EXECUTION_CAPABILITIES, sizeof(avail), &avail, NULL);
        fprintf(stdout, "\tCL_DEVICE_EXECUTION_CAPIBILITIES: %s\n", (avail == CL_TRUE) ? "TRUE" : "FALSE");
*/

	cl_ulong longbuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, sizeof(longbuf), &longbuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_GLOBAL_MEM_CACHE_SIZE(bytes): %llu\n", longbuf);


	cl_device_mem_cache_type typebuf = CL_NONE;
	clGetDeviceInfo(devices[i], CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, sizeof(typebuf), &typebuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_GLOBAL_MEM_CACHE_TYPE: %s\n", (typebuf == CL_NONE) ? "CL_NONE" :
		(typebuf == CL_READ_ONLY_CACHE) ? "CL_READ_ONLY_CACHE" :
		(typebuf == CL_READ_WRITE_CACHE) ? "CL_READ_WRITE_CACHE" : "BAD MAGIC");

	intbuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, sizeof(intbuf), &intbuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE(bytes): %u\n", intbuf);

	avail = CL_FALSE;
	clGetDeviceInfo(devices[i], CL_DEVICE_IMAGE_SUPPORT, sizeof(avail), &avail, NULL);
        fprintf(stdout, "\tCL_DEVICE_IMAGE_SUPPORT: %s\n", (avail == CL_TRUE) ? "TRUE" : "FALSE");

	size_t sizebuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_IMAGE2D_MAX_HEIGHT, sizeof(sizebuf), &sizebuf, NULL);
	fprintf(stdout, "\tCL_DEVICE_IMAGE2D_MAX_HEIGHT: %u\n", sizebuf);

	sizebuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_IMAGE2D_MAX_WIDTH, sizeof(sizebuf), &sizebuf, NULL);
	fprintf(stdout, "\tCL_DEVICE_IMAGE2D_MAX_WIDTH: %u\n", sizebuf);

	sizebuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_IMAGE3D_MAX_DEPTH, sizeof(sizebuf), &sizebuf, NULL);
	fprintf(stdout, "\tCL_DEVICE_IMAGE3D_MAX_DEPTH: %u\n", sizebuf);

	sizebuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_IMAGE3D_MAX_HEIGHT, sizeof(sizebuf), &sizebuf, NULL);
	fprintf(stdout, "\tCL_DEVICE_IMAGE3D_MAX_HEIGHT: %u\n", sizebuf);

	sizebuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_IMAGE3D_MAX_WIDTH, sizeof(sizebuf), &sizebuf, NULL);
	fprintf(stdout, "\tCL_DEVICE_IMAGE3D_MAX_WIDTH: %u\n", sizebuf);

	longbuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_LOCAL_MEM_SIZE, sizeof(longbuf), &longbuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_LOCAL_MEM_CACHE_SIZE(bytes): %llu\n", longbuf);

	intbuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(intbuf), &intbuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_MAX_CLOCK_FREQUENCY: %u\n", intbuf);

	intbuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(intbuf), &intbuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_MAX_COMPUTE_UNITS: %u\n", intbuf);


	intbuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_MAX_CONSTANT_ARGS, sizeof(intbuf), &intbuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_MAX_CONSTANT_ARGS: %u\n", intbuf);

	longbuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, sizeof(longbuf), &longbuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_MAX_CONSTANT_BUFFER_SIZE: %llu\n", longbuf);

	longbuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(longbuf), &longbuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_MAX_MEM_ALLOC_SIZE: %llu\n", longbuf);

	sizebuf = 0;
	clGetDeviceInfo(devices[i], CL_DEVICE_MAX_PARAMETER_SIZE, sizeof(sizebuf), &sizebuf, NULL);
        fprintf(stdout, "\tCL_DEVICE_MAX_MEM_ALLOC_SIZE: %u\n", sizebuf);

    }
    free(devices);
}
