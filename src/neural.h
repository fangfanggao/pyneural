#ifndef NEURAL_H
#define NEURAL_H

struct neural_net_layer {
	float *bias;
	float *theta;
	float *act;
	float *delta;
	struct neural_net_layer *prev;
	struct neural_net_layer *next;
	int in_nodes;
	int out_nodes;
};

void
neural_feed_forward(struct neural_net_layer *head, float *x, const int batch_size);

void
neural_sgd_feed_forward(struct neural_net_layer *head, float *x);

void
neural_back_prop(struct neural_net_layer *tail, float *y, const int batch_size,
		const float alpha, const float lambda);

void
neural_sgd_back_prop(struct neural_net_layer *tail, float *y,
		const float alpha, const float lambda);

void
neural_train_iteration(struct neural_net_layer *head, struct neural_net_layer *tail,
		float *features, float *labels, const int n_samples, const int batch_size,
		const float alpha, const float lambda);

void
neural_predict_prob(struct neural_net_layer *head, struct neural_net_layer *tail,
		float *features, float *preds, const int n_samples, const int batch_size);

#endif
